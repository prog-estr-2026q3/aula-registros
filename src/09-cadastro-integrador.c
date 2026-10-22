#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CAPACIDADE_MAX 5
#define TAM_NOME 50

typedef struct Aluno {
    double cr;
    unsigned int ra;
    char nome[TAM_NOME];
} Aluno;

/* ========================================================================= */
/* 1. OPERACOES DE MANIPULACAO DE DADOS (CRUD)                               */
/* ========================================================================= */

/* Consulta: busca linear por RA. Retorna o indice ou -1 se nao existir */
int buscar_por_ra(const Aluno turma[], size_t qtd, unsigned int ra) {
    for (size_t i = 0; i < qtd; i++) {
        if (turma[i].ra == ra) {
            return (int)i;
        }
    }
    return -1;
}

/* Insercao: valida capacidade e unicidade de RA */
bool inserir_aluno(Aluno turma[], size_t *qtd, size_t capacidade, Aluno novo) {
    if (*qtd >= capacidade || buscar_por_ra(turma, *qtd, novo.ra) != -1) {
        return false;
    }
    turma[*qtd] = novo;
    (*qtd)++;
    return true;
}

/* Atualizacao: altera o CR validando o intervalo de notas [0.0, 4.0] */
bool atualizar_cr(Aluno turma[], size_t qtd, unsigned int ra, double novo_cr) {
    if (novo_cr < 0.0 || novo_cr > 4.0) {
        return false;
    }
    int pos = buscar_por_ra(turma, qtd, ra);
    if (pos == -1) {
        return false;
    }
    turma[pos].cr = novo_cr;
    return true;
}

/* Remocao: localiza por RA e compacta os elementos a esquerda */
bool remover_aluno(Aluno turma[], size_t *qtd, unsigned int ra) {
    int pos = buscar_por_ra(turma, *qtd, ra);
    if (pos == -1) {
        return false;
    }
    for (size_t i = (size_t)pos; i < (*qtd) - 1; i++) {
        turma[i] = turma[i + 1];
    }
    (*qtd)--;
    return true;
}

/* ========================================================================= */
/* 2. FUNCOES DE ENTRADA E SAIDA                                             */
/* ========================================================================= */

/* Exibe os dados formatados de um unico registro de aluno */
void imprimir_aluno(const Aluno *a) {
    printf("RA: %-10u | CR: %4.2f | Nome: %s\n", a->ra, a->cr, a->nome);
}

/* Captura dados via teclado utilizando scanf por simplicidade */
void ler_aluno(Aluno *a) {
    printf("Digite o RA: ");
    scanf("%u", &a->ra);
    printf("Digite o Nome: ");
    scanf("%49s", a->nome);
    printf("Digite o CR: ");
    scanf("%lf", &a->cr);
}

/* ========================================================================= */
/* 3. DEMONSTRACAO INTEGRADA                                                 */
/* ========================================================================= */

int main(void) {
    Aluno turma[CAPACIDADE_MAX];
    size_t qtd = 0;
    int op;

    while (1) {
        printf("\n1-Inserir 2-Buscar 3-Atualizar 4-Remover 5-Listar 0-Sair\nOpcao: ");
        if (scanf("%d", &op) != 1 || op == 0) {
            break;
        }

        switch (op) {
            case 1: {
                Aluno novo;
                ler_aluno(&novo);
                if (!inserir_aluno(turma, &qtd, CAPACIDADE_MAX, novo)) {
                    printf("Falha: turma cheia ou RA duplicado.\n");
                }
                break;
            }
            case 2: {
                unsigned int ra;
                printf("RA: ");
                scanf("%u", &ra);
                int pos = buscar_por_ra(turma, qtd, ra);
                if (pos != -1) {
                    imprimir_aluno(&turma[pos]);
                } else {
                    printf("Aluno nao encontrado.\n");
                }
                break;
            }
            case 3: {
                unsigned int ra;
                double cr;
                printf("RA e novo CR: ");
                scanf("%u %lf", &ra, &cr);
                if (!atualizar_cr(turma, qtd, ra, cr)) {
                    printf("Falha na atualizacao.\n");
                }
                break;
            }
            case 4: {
                unsigned int ra;
                printf("RA: ");
                scanf("%u", &ra);
                if (!remover_aluno(turma, &qtd, ra)) {
                    printf("Aluno nao encontrado.\n");
                }
                break;
            }
            case 5:
                for (size_t i = 0; i < qtd; i++) {
                    imprimir_aluno(&turma[i]);
                }
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
}
