#include <stdio.h>

typedef struct Data {
    int dia, mes, ano;
} Data;

typedef struct Aluno {
    char nome[50];
    unsigned int ra;
    Data nascimento;
} Aluno;

int main(void) {
    Aluno a1 = {"Mariana Costa", 11202315, {15, 8, 2003}};

    /* Acesso aos campos por encadeamento de operadores ponto */
    printf("Nascimento: %02d/%02d/%04d\n",
           a1.nascimento.dia, a1.nascimento.mes, a1.nascimento.ano);

    /* Contiguidade: endereco do membro aninhado coincide com seu primeiro campo */
    printf("&a1.nascimento:     %p\n", (void *)&a1.nascimento);
    printf("&a1.nascimento.dia: %p\n", (void *)&a1.nascimento.dia);

    return 0;
}
