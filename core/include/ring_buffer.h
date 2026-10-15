#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#define RING_CAPACITY 32

typedef struct{
    uint8_t data[RING_CAPACITY];
    size_t head;
    size_t tail;
    size_t count;
} ring_buffer_t;

void ring_init(ring_buffer_t *rb);
bool ring_push(ring_buffer_t *rb, uint8_t value);
bool ring_pop(ring_buffer_t *rb, uint8_t *out);

#endif