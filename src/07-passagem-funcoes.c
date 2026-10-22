#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    double cr;
    unsigned int ra;
    char nome[50];
} Aluno;

/* 1. Criacao e retorno por valor (seguro quanto ao ciclo de vida) */
Aluno criar_aluno(const char *nome, unsigned int ra, double cr) {
    Aluno novo = {.cr = cr, .ra = ra};
    strncpy(novo.nome, nome, sizeof(novo.nome) - 1);
    novo.nome[sizeof(novo.nome) - 1] = '\0';
    return novo; /* Retorno por valor: copia a estrutura para o chamador */
}

/* 2. Passagem por valor: duplicacao integral dos bytes na pilha */
void exibir_por_valor(Aluno a) {
    printf("[exibir_por_valor] Endereco do parametro a: %p\n", (void *)&a);
    printf("[exibir_por_valor] Aluno: %s | RA: %u | CR: %.2f\n", a.nome, a.ra, a.cr);
    a.cr = 0.0; /* Modifica apenas a copia local no stack frame */
}

/* 3. Passagem por ponteiro constante: somente leitura eficiente (8 bytes) */
void exibir_por_referencia(const Aluno *a) {
    printf("[exibir_por_referencia] Endereco apontado:  %p\n", (void *)a);
    printf("[exibir_por_referencia] Aluno: %s | RA: %u | CR: %.2f\n", a->nome, a->ra, a->cr);
    /* a->cr = 0.0; // ERRO de compilacao: membro e somente leitura */
}

/* 4. Passagem por ponteiro mutavel: parametro de saida para modificacao */
void atualizar_cr(Aluno *a, double novo_cr) {
    if (a != NULL && novo_cr >= 0.0 && novo_cr <= 4.0) {
        a->cr = novo_cr; /* Altera diretamente a instancia no chamador */
    }
}

int main(void) {
    Aluno a1 = criar_aluno("Mariana Costa", 11202315, 3.75);

    printf("=== Instancia original em main ===\n");
    printf("Endereco de a1: %p (tamanho: %zu bytes)\n\n", (void *)&a1, sizeof(a1));

    printf("=== Teste 1: Passagem por valor ===\n");
    exibir_por_valor(a1);
    printf("Apos exibir_por_valor em main: CR = %.2f (inalterado)\n\n", a1.cr);

    printf("=== Teste 2: Passagem por const Aluno* ===\n");
    exibir_por_referencia(&a1);
    printf("\n");

    printf("=== Teste 3: Mutacao via Aluno* ===\n");
    atualizar_cr(&a1, 3.90);
    printf("Apos atualizar_cr em main: CR = %.2f (modificado)\n", a1.cr);

    return 0;
}
