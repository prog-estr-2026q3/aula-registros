#include <stdio.h>
#include <stddef.h>

struct Desordenada {
    char a;      /* 1 byte */
    int b;       /* 4 bytes */
    char c;      /* 1 byte */
};

struct Otimizada {
    int b;       /* 4 bytes */
    char a;      /* 1 byte */
    char c;      /* 1 byte */
};

int main(void) {
    printf("Desordenada: %zu bytes (offsets: a=%zu, b=%zu, c=%zu)\n",
           sizeof(struct Desordenada),
           offsetof(struct Desordenada, a),
           offsetof(struct Desordenada, b),
           offsetof(struct Desordenada, c));

    printf("Otimizada:   %zu bytes (offsets: b=%zu, a=%zu, c=%zu)\n",
           sizeof(struct Otimizada),
           offsetof(struct Otimizada, b),
           offsetof(struct Otimizada, a),
           offsetof(struct Otimizada, c));

    return 0;
}
