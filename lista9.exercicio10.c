#include <stdio.h>
#include <string.h>

#define MAX 4 

struct aluno {
    char nome[81];
    float media;
};

void le(struct aluno turma[]) {
    for (int i = 0; i < MAX; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(turma[i].nome, 81, stdin);
        // Remove o \n do nome se existir
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0';

        printf("Digite a média de %s: ", turma[i].nome);
        scanf("%f", &turma[i].media);
        getchar(); // consome o '\n' deixado pelo scanf
    }
}

void imprime(struct aluno turma[]) {
    for (int i = 0; i < MAX; i++) {
        printf("Aluno: %s - Média: %.2f\n", turma[i].nome, turma[i].media);
    }
}

void ordena_medias(struct aluno turma[]) {
    int i, j;
    struct aluno temp;

    for (i = 0; i < MAX - 1; i++) {
        for (j = 0; j < MAX - 1 - i; j++) {
            if (turma[j].media > turma[j + 1].media) {
                temp = turma[j];
                turma[j] = turma[j + 1];
                turma[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    struct aluno turma[MAX];

    le(turma);

    puts("Imprimindo dados lidos da turma.");
    puts("Digite qualquer coisa para continuar.");
    getchar();
    imprime(turma);

    ordena_medias(turma);

    puts("Imprimindo dados ordenados da turma.");
    puts("Digite qualquer coisa para continuar.");
    getchar();
    imprime(turma);

    getchar(); 
    return 0;
}
