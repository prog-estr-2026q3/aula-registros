#include <stdio.h>

typedef struct Aluno {
    double cr;
    unsigned int ra;
    char nome[50];
} Aluno;

int main(void) {
    Aluno a1 = {3.40, 11202410, "Lucas Ribeiro"};
    Aluno *ptr = &a1;

    /* 1. Acesso direto (.) */
    printf("a1.cr:        %.2f\n", a1.cr);

    /* 2. Ponteiro com desreferenciacao explicita: (*ptr).campo */
    (*ptr).cr = 3.60;
    printf("(*ptr).cr:    %.2f\n", (*ptr).cr);

    /* 3. Ponteiro com operador seta idiomatico: ptr->campo */
    ptr->cr = 3.80;
    printf("ptr->cr:      %.2f (a1.cr: %.2f)\n", ptr->cr, a1.cr);

    return 0;
}
