#include <stdio.h>
#include <stdlib.h>


/*3. Sabendo que:
Matriz original: Transposta:
1 3 4 5 1 3 7 3
3 6 8 9 => 3 6 2 2
7 2 4 5 4 8 4 1
3 2 1 5 5 9 5 5
E ainda sabendo que uma matriz sim�trica � aquela em que a matriz original � igual a
sua transposta, fa�a uma fun��o que identifique se uma matriz � sim�trica. Utilize
fun��es para cada atividade do programa.*/


#include <stdio.h>
#define TAM 4

// Fun��o para ler a matriz
void lerMatriz(int matriz[TAM][TAM]) {
    printf("Digite os elementos da matriz %dx%d:\n", TAM, TAM);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Fun��o para imprimir a matriz
void imprimirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Fun��o para calcular a transposta
void transporMatriz(int original[TAM][TAM], int transposta[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            transposta[j][i] = original[i][j];
        }
    }
}

// Fun��o para verificar se � sim�trica
int ehSimetrica(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return 0; // Falso
            }
        }
    }
    return 1; // Verdadeiro
}

int main() {
    int matriz[TAM][TAM];
    int transposta[TAM][TAM];

    lerMatriz(matriz);

    printf("\nMatriz original:\n");
    imprimirMatriz(matriz);

    transporMatriz(matriz, transposta);

    printf("\nMatriz transposta:\n");
    imprimirMatriz(transposta);

    if (ehSimetrica(matriz)) {
        printf("\nA matriz � sim�trica.\n");
    } else {
        printf("\nA matriz N�O � sim�trica.\n");
    }

    return 0;
}
