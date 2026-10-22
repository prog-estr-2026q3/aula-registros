#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ALUNOS 5

typedef struct Aluno {
    double cr;
    unsigned int ra;
    char nome[50];
} Aluno;

/* Exibe a colecao formatada como tabela */
void exibir_turma(const Aluno turma[], size_t qtd) {
    printf("----------------------------------------------------------------\n");
    printf("%-4s | %-10s | %-25s | %s\n", "Pos", "RA", "Nome", "CR");
    printf("----------------------------------------------------------------\n");
    for (size_t i = 0; i < qtd; i++) {
        printf("[%zu]  | %-10u | %-25s | %.2f\n",
               i, turma[i].ra, turma[i].nome, turma[i].cr);
    }
    printf("----------------------------------------------------------------\n");
    printf("Total cadastrado: %zu / %d alunos\n\n", qtd, MAX_ALUNOS);
}

/* Insere um novo aluno se houver capacidade disponivel */
bool inserir_aluno(Aluno turma[], size_t *qtd, size_t capacidade, Aluno novo) {
    if (*qtd >= capacidade) {
        return false; /* Capacidade esgotada */
    }
    turma[*qtd] = novo; /* Copia integral bit a bit para a posicao livre */
    (*qtd)++;
    return true;
}

/* Remove o elemento no indice especificado preservando a contiguidade */
bool remover_aluno(Aluno turma[], size_t *qtd, size_t pos) {
    if (pos >= *qtd) {
        return false; /* Indice fora dos limites validos */
    }
    /* Desloca os elementos subsequentes para a esquerda */
    for (size_t i = pos; i < (*qtd) - 1; i++) {
        turma[i] = turma[i + 1];
    }
    (*qtd)--;
    return true;
}

int main(void) {
    Aluno turma[MAX_ALUNOS];
    size_t qtd = 0;

    printf("=== 1. Insercao de Alunos ===\n");
    inserir_aluno(turma, &qtd, MAX_ALUNOS, (Aluno){3.75, 11202021, "Ana Silva"});
    inserir_aluno(turma, &qtd, MAX_ALUNOS, (Aluno){3.80, 11202315, "Mariana Costa"});
    inserir_aluno(turma, &qtd, MAX_ALUNOS, (Aluno){2.90, 11201980, "Carlos Eduardo"});
    inserir_aluno(turma, &qtd, MAX_ALUNOS, (Aluno){3.95, 11202204, "Beatriz Ramos"});

    exibir_turma(turma, qtd);

    printf("=== 2. Enderecamento fisico contiguo ===\n");
    printf("Tamanho de cada Aluno: %zu bytes\n", sizeof(Aluno));
    for (size_t i = 0; i < qtd; i++) {
        printf("&turma[%zu]: %p (offset: +%zu bytes)\n",
               i, (void *)&turma[i], (size_t)((char *)&turma[i] - (char *)&turma[0]));
    }
    printf("\n");

    printf("=== 3. Remocao do elemento no indice [2] (Carlos Eduardo) ===\n");
    if (remover_aluno(turma, &qtd, 2)) {
        printf("Elemento removido com sucesso.\n");
    }
    exibir_turma(turma, qtd);

    return 0;
}
