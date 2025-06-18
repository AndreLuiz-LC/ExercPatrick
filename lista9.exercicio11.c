#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    int matricula;
    float *vNotas;  // 5 notas do aluno
    char nome[100];
} Aluno;

typedef struct Materia {
    Aluno *V;       // vetor de alunos
    float media[5]; // média de cada prova
    int nAlunos;    // número de alunos
} Materia;

Aluno* fillAluno() {
    Aluno *a = malloc(sizeof(Aluno));
    if (!a) {
        printf("Erro de alocação.\n");
        exit(1);
    }

    printf("Digite a matrícula: ");
    scanf("%d", &a->matricula);
    getchar(); // limpar '\n'

    printf("Digite o nome: ");
    fgets(a->nome, 100, stdin);
    a->nome[strcspn(a->nome, "\n")] = '\0'; // remove '\n'

    a->vNotas = malloc(5 * sizeof(float));
    if (!a->vNotas) {
        printf("Erro de alocação para notas.\n");
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &a->vNotas[i]);
    }
    getchar(); // limpar '\n'

    return a;
}

Materia* fillMateria(int numAlunos) {
    Materia *m = malloc(sizeof(Materia));
    if (!m) {
        printf("Erro de alocação para Materia.\n");
        exit(1);
    }

    m->nAlunos = numAlunos;
    m->V = malloc(numAlunos * sizeof(Aluno));
    if (!m->V) {
        printf("Erro de alocação para vetor de alunos.\n");
        exit(1);
    }

    for (int i = 0; i < numAlunos; i++) {
        Aluno *aux = fillAluno();
        m->V[i] = *aux; // copia o conteúdo
        free(aux);       // libera auxiliar
    }

    return m;
}

void mediaMateria(Materia *m1) {
    for (int i = 0; i < 5; i++) {
        float soma = 0;
        for (int j = 0; j < m1->nAlunos; j++) {
            soma += m1->V[j].vNotas[i];
        }
        m1->media[i] = soma / m1->nAlunos;
    }
}

void mostraMateria(Materia *m1) {
    printf("\n--- Alunos ---\n");
    for (int i = 0; i < m1->nAlunos; i++) {
        printf("Matricula: %d\n", m1->V[i].matricula);
        printf("Nome: %s\n", m1->V[i].nome);
        printf("Notas: ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", m1->V[i].vNotas[j]);
        }
        printf("\n\n");
    }

    printf("--- Médias da matéria ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Prova %d: %.2f\n", i + 1, m1->media[i]);
    }
}

int main() {
    int n;

    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    getchar(); // limpar '\n'

    Materia *m = fillMateria(n);

    mediaMateria(m);

    mostraMateria(m);

    // Liberar memória
    for (int i = 0; i < m->nAlunos; i++) {
        free(m->V[i].vNotas);
    }
    free(m->V);
    free(m);

    return 0;
}