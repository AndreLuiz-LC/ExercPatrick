#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definições das structs
typedef struct aluno {
    int mat;           // matrícula
    char nome[81];     // nome do aluno
} Aluno;

typedef struct prova {
    Aluno a;           // aluno que fez a prova
    float q1, q2, q3, q4; // notas das 4 questões
} Prova;

// Função que compara dois elementos
int compara(Prova *p1, Prova *p2) {
    float nota1 = p1->q1 + p1->q2 + p1->q3 + p1->q4;
    float nota2 = p2->q1 + p2->q2 + p2->q3 + p2->q4;

    if (nota1 < nota2) {
        return 1; // p1 deve vir depois
    } else if (nota1 == nota2) {
        if (strcmp(p1->a.nome, p2->a.nome) > 0) {
            return 1; // p1 vem depois alfabeticamente
        }
    }
    return 0;
}

// Função que troca dois ponteiros de Prova
void troca(Prova **x, Prova **y) {
    Prova *temp = *x;
    *x = *y;
    *y = temp;
}

// Algoritmo de ordenação bolha
void ordena(int n, Prova **v) {
    int fim, i;
    for (fim = n - 1; fim > 0; fim--) {
        for (i = 0; i < fim; i++) {
            if (compara(v[i], v[i + 1])) {
                troca(&v[i], &v[i + 1]);
            }
        }
    }
}

int main() {
    // Número de provas
    int n = 3;
    Prova *provas[n];

    // Alocando e preenchendo manualmente
    provas[0] = malloc(sizeof(Prova));
    provas[0]->a.mat = 1;
    strcpy(provas[0]->a.nome, "Maria");
    provas[0]->q1 = 1.5; provas[0]->q2 = 1.5; provas[0]->q3 = 1.5; provas[0]->q4 = 1.5;

    provas[1] = malloc(sizeof(Prova));
    provas[1]->a.mat = 2;
    strcpy(provas[1]->a.nome, "Ana");
    provas[1]->q1 = 2.0; provas[1]->q2 = 1.0; provas[1]->q3 = 1.5; provas[1]->q4 = 1.5;

    provas[2] = malloc(sizeof(Prova));
    provas[2]->a.mat = 3;
    strcpy(provas[2]->a.nome, "Sandra");
    provas[2]->q1 = 2.0; provas[2]->q2 = 2.0; provas[2]->q3 = 2.0; provas[2]->q4 = 1.0;

    // Ordenar as provas
    ordena(n, provas);

    // Mostrar resultado
    printf("Provas ordenadas:\n");
    for (int i = 0; i < n; i++) {
        float nota = provas[i]->q1 + provas[i]->q2 + provas[i]->q3 + provas[i]->q4;
        printf("Nome: %s | Matrícula: %d | Nota Total: %.2f\n",
               provas[i]->a.nome, provas[i]->a.mat, nota);
    }

    // Liberar memória
    for (int i = 0; i < n; i++) {
        free(provas[i]);
    }

    return 0;
}
