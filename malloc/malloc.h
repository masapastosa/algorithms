#ifndef MALLOC_HH
#define MALLOC_HH

typedef struct meta_block {
    size_t size;
    struct meta_block *next;
    int free;
    int magic;
} meta_block_t;

#define META_SIZE sizeof(meta_block_t)

meta_block_t *find_free_block(meta_block_t **last, size_t size);
meta_block_t *request_space(meta_block_t *last, size_t size);
meta_block_t *get_block_ptr(void *mem);
void *malloc(size_t size);
void free(void *ptr);

#endif
