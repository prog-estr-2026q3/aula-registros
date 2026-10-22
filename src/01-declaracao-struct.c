#include <stdio.h>

struct Aluno {
    char conceito;
    int ra;
    double cr;
};

int main(void) {
    struct Aluno a1 = {'A', 11202410, 3.40};

    printf("&a1:          %p\n", (void *)&a1);
    printf("&a1.conceito: %p\n", (void *)&a1.conceito);
    printf("&a1.ra:       %p\n", (void *)&a1.ra);
    printf("&a1.cr:       %p\n", (void *)&a1.cr);
    printf("sizeof(struct Aluno): %zu bytes (soma dos campos: %zu bytes)\n",
           sizeof(a1), sizeof(a1.conceito) + sizeof(a1.ra) + sizeof(a1.cr));

    return 0;
}
