#include<sys/mman.h>
#include<unistd.h>
#include<stddef.h>
#include<stdint.h>

#include<heap.h>

typedef struct block_header{

	size_t size;
	size_t total_size;
}block_header_t;

static size_t align16(size_t n){
	return (n+15)&~((size_t)15);
}

void* heap_alloc(size_t size){
	if(size==0)
		return NULL;
	size=align16(size);
	size_t header_size=sizeof(block_header_t);
	size_t total=size+header_size;
	
	size_t page_size=sysconf(_SC_PAGESIZE);
	size_t mmap_size=(total+page_size-1)& ~(page_size-1);
	
	void*mem=mmap(NULL,mmap_size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	
	if(mem==MAP_FAILED)
		return NULL;

	block_header_t *hdr=(block_header_t*)mem;
	hdr->size=size;
	hdr->total_size=mmap_size;

	return (void*)(hdr+1);

}

void heap_free(void  *ptr){
	
	if(!ptr)
		return;
	block_header_t *hdr=(block_header_t *)ptr-1;
	munmap((void*)hdr, hdr->total_size);
	
}

