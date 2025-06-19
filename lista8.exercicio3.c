#include <stdio.h>
#include <stdlib.h>


/*3. Sabendo que:
Matriz original: Transposta:
1 3 4 5 1 3 7 3
3 6 8 9 => 3 6 2 2
7 2 4 5 4 8 4 1
3 2 1 5 5 9 5 5
E ainda sabendo que uma matriz simétrica é aquela em que a matriz original é igual a
sua transposta, faça uma função que identifique se uma matriz é simétrica. Utilize
funções para cada atividade do programa.*/


#include <stdio.h>
#define TAM 4

// Função para ler a matriz
void lerMatriz(int matriz[TAM][TAM]) {
    printf("Digite os elementos da matriz %dx%d:\n", TAM, TAM);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para imprimir a matriz
void imprimirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para calcular a transposta
void transporMatriz(int original[TAM][TAM], int transposta[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            transposta[j][i] = original[i][j];
        }
    }
}

// Função para verificar se é simétrica
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
        printf("\nA matriz é simétrica.\n");
    } else {
        printf("\nA matriz NÃO é simétrica.\n");
    }

    return 0;
}
