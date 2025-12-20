#include<sys/mman.h>
#include<unistd.h>
#include<stddef.h>
#include<stdint.h>

#include<heap.h>

typedef struct block_header{

	size_t size;
	size_t total_size;
}block_header_t;


