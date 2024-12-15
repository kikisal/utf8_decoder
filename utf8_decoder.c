#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef struct fbuf_st {
    u8*    data;
    size_t buf_read;
    size_t len;
} fbuf_t;

fbuf_t fbuf_create(size_t len) {
    u8* data = malloc(sizeof(len));

    return (fbuf_t){.data = data, .len = len};
}

typedef struct uc32string_st {
    u32* points;
    size_t cap;
    size_t len;
} uc32string_t;

uc32string_t uc32_string_create(size_t cap) {
    return (uc32string_t){.points = malloc(cap * sizeof(u32)), .cap = cap, .len = 0};
}

void uc32_string_append(uc32string_t* str, u32 point) {
    str->points[str->len] = point;
    str->len++;
}

uc32string_t utf8_decode(fbuf_t buff) {
    uc32string_t str = uc32_string_create(1024);

    u8 leading = fbuf_read_u8(buff, 1);
    if (leading & 0x70) {
        
    } else {
        // it is ascii char
        uc32_string_append(&str, (u32) leading);
    }
}

int main() {

    fbuf_t buff = fbuf_create(1024);
    
    
    utf8_decode(buff);


    return 0;
}
