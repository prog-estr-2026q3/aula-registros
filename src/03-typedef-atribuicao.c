#include <stdio.h>
#include <string.h>

/* Definicao combinada de estrutura e alias com typedef.
   Campos ordenados de forma decrescente para minimizar padding:
   double (8 bytes) -> unsigned int (4 bytes) -> char[50] (50 bytes). */
typedef struct Aluno {
    double cr;
    unsigned int ra;
    char nome[50];
} Aluno;

int main(void) {
    /* Instanciacao idiomatica utilizando o alias Aluno */
    Aluno a1 = {
        .cr = 3.75,
        .ra = 11202021,
        .nome = "Ana Silva"
    };

    /* Atribuicao direta: copia integral dos bytes de a1 para a2 */
    Aluno a2 = a1;

    /* Modificacao em a2 para evidenciar a independencia de memoria */
    a2.cr = 3.90;
    strcpy(a2.nome, "Ana Paula Silva");

    printf("a1: %s, RA: %u, CR: %.2f (endereco: %p)\n",
           a1.nome, a1.ra, a1.cr, (void *)&a1);
    printf("a2: %s, RA: %u, CR: %.2f (endereco: %p)\n",
           a2.nome, a2.ra, a2.cr, (void *)&a2);

    return 0;
}
