# mmap-based Heap Allocator (Custom `heap_alloc` / `heap_free`)

This project implements a **custom heap allocator in C** that uses **only OS system calls (`mmap` / `munmap`)** instead of `malloc` and `free`.

The goal of this project is **educational and systems-oriented**:
- understand how heap allocators work internally
- understand page-based virtual memory
- understand alignment, metadata, and pointer arithmetic
- build a clean allocator with a minimal, correct design

This allocator is **thread-safe by design** (no shared state) and intentionally simple.
---

##  Public API

Declared in `include/heap.h`:

```c
void *heap_alloc(size_t size);
void  heap_free(void *ptr);

------------------------------------------------------
│ block_header_t (metadata) │ user payload           │
------------------------------------------------------
^                           ^
mmap base                   pointer returned to user

