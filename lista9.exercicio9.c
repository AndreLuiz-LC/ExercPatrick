#include <stdio.h>
#include <string.h>

typedef struct aluno {
    char nome[81];
    float media;
} ALUNO;

void ordena(ALUNO turma[], int tam) {
    int i, foraOrdem, jaOrdenados = 0;
    ALUNO temp;

    do {
        foraOrdem = 0;
        for (i = 0; i < tam - 1 - jaOrdenados; i++) {
            if (turma[i].media > turma[i + 1].media) {
                temp = turma[i];
                turma[i] = turma[i + 1];
                turma[i + 1] = temp;
                foraOrdem = 1;
            }
        }
        jaOrdenados++;
    } while (foraOrdem);
}

int main() {
    ALUNO turma[4] = {
        {"Maria", 7.5},
        {"Joao", 5.0},
        {"Ana", 8.0},
        {"Bruno", 6.0}
    };

    int i;

    printf("Antes da ordenação:\n");
    for (i = 0; i < 4; i++) {
        printf("%s - Média: %.2f\n", turma[i].nome, turma[i].media);
    }

    ordena(turma, 4);

    printf("\nDepois da ordenação (por média crescente):\n");
    for (i = 0; i < 4; i++) {
        printf("%s - Média: %.2f\n", turma[i].nome, turma[i].media);
    }

    return 0;
}
