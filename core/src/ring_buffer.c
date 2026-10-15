#include "ring_buffer.h"

void ring_init(ring_buffer_t *rb){
    if(rb == NULL)
        return;
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

bool ring_push(ring_buffer_t *rb, uint8_t value){
    if(rb == NULL)
        return false;

    if(rb->count >= RING_CAPACITY)
        return false;
    
    rb->data[rb->tail] = value;
    rb->tail = (rb->tail + 1) % RING_CAPACITY;
    rb->count++;

    return true; 
}

bool ring_pop(ring_buffer_t *rb, uint8_t *out){
    if(rb == NULL || out == NULL)
        return false;
    
    if(rb->count == 0)
        return false;

    *out = rb->data[rb->head];
    rb->head = (rb->head + 1) % RING_CAPACITY;
    rb->count--;

    return true;
}