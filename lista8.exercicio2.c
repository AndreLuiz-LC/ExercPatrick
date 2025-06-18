#include <stdio.h>
#include <stdlib.h>

/*2. Escreva um programa em linguagem C que faça a leitura e calcule a soma de duas
matrizes.*/

#define LINHAS 3
#define COLUNAS 4

int main() {
    int matriz1[LINHAS][COLUNAS];
    int matriz2[LINHAS][COLUNAS];
    int resultado[LINHAS][COLUNAS];

    // Leitura da primeira matriz
    printf("Digite os elementos da primeira matriz (%dx%d):\n", LINHAS, COLUNAS);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Leitura da segunda matriz
    printf("Digite os elementos da segunda matriz (%dx%d):\n", LINHAS, COLUNAS);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Soma das duas matrizes
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Impressão do resultado
    printf("\nMatriz resultante da soma:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d\t", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
