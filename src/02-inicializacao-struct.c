#include <stdio.h>

struct Aluno {
    char nome[50];
    unsigned int ra;
    double cr;
};

int main(void) {
    /* 1. Inicializacao posicional classica */
    struct Aluno a1 = {"Ana Silva", 11202021, 3.75};

    /* 2. Inicializadores designados (C99) */
    struct Aluno a2 = {
        .nome = "Bruno Santos",
        .ra = 11202022,
        .cr = 3.30
    };

    /* 3. Inicializacao com membros omitidos (cr sera automaticamente 0.0) */
    struct Aluno a3 = {
        .nome = "Carla Souza",
        .ra = 11202023
    };

    /* 4. Inicializacao zerada integral */
    struct Aluno a4 = {0};

    printf("a1: %s, RA: %u, CR: %.2f\n", a1.nome, a1.ra, a1.cr);
    printf("a2: %s, RA: %u, CR: %.2f\n", a2.nome, a2.ra, a2.cr);
    printf("a3: %s, RA: %u, CR: %.2f (CR omitido foi zerado)\n", a3.nome, a3.ra, a3.cr);
    printf("a4: [%s], RA: %u, CR: %.2f (todos zerados)\n", a4.nome, a4.ra, a4.cr);

    return 0;
}
