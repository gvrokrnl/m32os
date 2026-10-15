#include <assert.h>
#include "ring_buffer.h"

int main(void){
    ring_buffer_t rb;
    ring_init(&rb);

    assert(rb.head == 0);
    assert(rb.tail == 0);
    assert(rb.count == 0);

    return 0;
}