#include <unistd.h>
#include <assert.h>
#include "malloc.h"

meta_block_t *global_base = NULL;

meta_block_t *find_free_block(meta_block_t **last, size_t size) {
    meta_block_t *curr = global_base;
    *last = NULL;
    while (curr && !(curr->size >= size && curr->free)) {
        *last = curr;
        curr = curr->next;
    }
    if (curr && (curr->size - size) > MIN_SPLIT_VALUE) {
        // If the new block is > 16 bytes than requestes size, create a new block
        uint8_t *ptr = (uint8_t*)(curr + 1);
        meta_block_t *new_block = (meta_block_t *)(ptr + size);
        new_block->size = curr->size - size - META_SIZE;
        new_block->next = curr->next;
        new_block->free = 1;
        new_block->magic = 0xffffffff;
        curr->next = new_block;
        curr->size = size;
    }
    return curr;
}

meta_block_t *request_space(meta_block_t *last, size_t size) {
    meta_block_t *block;
    block = sbrk(0);
    void *req = sbrk(size + META_SIZE);
    assert((void*)block == req);
    if (req == (void*) -1) return NULL;
    if (last) last->next = block;
    else global_base = block;
    block->size = size;
    block->next = NULL;
    block->free = 0;
    block->magic = 0x12345678;
    return block;
}

meta_block_t *get_block_ptr(void *mem) {
    return ((meta_block_t*)mem) - 1;
}

void *malloc(size_t size) {
    if (size <= 0) return NULL;
    meta_block_t *last;
    meta_block_t *block = find_free_block(&last, size);
    if (!block) {
        block = request_space(last, size);
        if (!block) return NULL;
    } else {
        block->free = 0;
        block->magic = 0x77777777;
    }

    return (block + 1);
}

void free(void *ptr) {
    if (!ptr) return;

    meta_block_t *block = get_block_ptr(ptr);
    if (block->free) return;
    block->free = 1;
    block->magic = 0x55555555;
}
