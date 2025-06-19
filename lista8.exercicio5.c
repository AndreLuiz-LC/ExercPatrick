//Questão 5

#include <stdio.h>
#define MAX 10

void soma_matrizes(int l, int c, int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX]) {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            R[i][j] = A[i][j] + B[i][j];
}

void soma_diagonais(int n, int M[MAX][MAX], int* soma_principal, int* soma_secundaria) {
    *soma_principal = 0;
    *soma_secundaria = 0;

    for (int i = 0; i < n; i++) {
        *soma_principal += M[i][i];
        *soma_secundaria += M[i][n - 1 - i];
    }
}

void multiplica_matrizes(int l1, int c1, int A[MAX][MAX], int l2, int c2, int B[MAX][MAX], int R[MAX][MAX]) {
    if (c1 != l2) {
        printf("As matrizes não podem ser multiplicadas!\n");
        return;
    }

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void imprime_matriz(int l, int c, int M[MAX][MAX]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], S[MAX][MAX], M[MAX][MAX];
    int n;

    printf("Digite a ordem das matrizes quadradas (max %d): ", MAX);
    scanf("%d", &n);

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    soma_matrizes(n, n, A, B, S);
    printf("\nSoma das matrizes A + B:\n");
    imprime_matriz(n, n, S);

    int diagA_pri, diagA_sec, diagB_pri, diagB_sec;
    soma_diagonais(n, A, &diagA_pri, &diagA_sec);
    soma_diagonais(n, B, &diagB_pri, &diagB_sec);

    printf("\nSoma das diagonais da matriz A: principal = %d, secundaria = %d\n", diagA_pri, diagA_sec);
    printf("Soma das diagonais da matriz B: principal = %d, secundaria = %d\n", diagB_pri, diagB_sec);

    multiplica_matrizes(n, n, A, n, n, B, M);
    printf("\nMultiplicação das matrizes A * B:\n");
    imprime_matriz(n, n, M);

    return 0;
}
