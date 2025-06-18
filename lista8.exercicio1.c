#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3

// Fun��o que verifica se todas as linhas t�m a mesma soma
int linhasComMesmaSoma(int matriz[LINHAS][COLUNAS]) {
    int somaReferencia = 0;

    // Soma da primeira linha
    for (int j = 0; j < COLUNAS; j++) {
        somaReferencia += matriz[0][j];
    }

    // Verifica as outras linhas
    for (int i = 1; i < LINHAS; i++) {
        int somaLinha = 0;
        for (int j = 0; j < COLUNAS; j++) {
            somaLinha += matriz[i][j];
        }
        if (somaLinha != somaReferencia) {
            return 0; // As somas s�o diferentes
        }
    }

    return 1; // Todas as somas s�o iguais
}

int main() {
    int matriz[LINHAS][COLUNAS] = {
        {2, 2, 2},
        {3, 1, 2},
        {1, 4, 1}
    };

    if (linhasComMesmaSoma(matriz)) {
        printf("Todas as linhas t�m a mesma soma.\n");
    } else {
        printf("As linhas t�m somas diferentes.\n");
    }

    return 0;
}
