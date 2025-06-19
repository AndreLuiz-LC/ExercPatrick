//Questão 6
#include <stdio.h>
//a)

#define TAM 8

int main() {
    int tabuleiro[TAM][TAM] = {
        {1, 3, 0, 5, 4, 0, 2, 1},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 6, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 4, 0, 0, 1, 0},
        {0, 0, 3, 1, 0, 0, 1, 1},
        {1, 0, 6, 6, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 1, 0, 6}
    };

    int soma_peoes_bispos = 0;
    int ausencias = 0;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 1 || tabuleiro[i][j] == 4)
                soma_peoes_bispos++;
            if (tabuleiro[i][j] == 0)
                ausencias++;
        }
    }

    printf("Soma total de peões e bispos: %d\n", soma_peoes_bispos);
    printf("Quantidade de posições vazias: %d\n", ausencias);

    return 0;
}

//b)

#define TAM 8

int main() {
    int tabuleiro[TAM][TAM] = {
        {1, 3, 0, 5, 4, 0, 2, 1},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 6, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 4, 0, 0, 1, 0},
        {0, 0, 3, 1, 0, 0, 1, 1},
        {1, 0, 6, 6, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 1, 0, 6}
    };

    int cont[7] = {0}; // índices: 0 até 6

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int peca = tabuleiro[i][j];
            if (peca >= 0 && peca <= 6)
                cont[peca]++;
        }
    }

    printf("Quantidade de cada peça no tabuleiro:\n");
    printf("Ausência de peça (0): %d\n", cont[0]);
    printf("Peões (1): %d\n", cont[1]);
    printf("Cavalos (2): %d\n", cont[2]);
    printf("Torres (3): %d\n", cont[3]);
    printf("Bispos (4): %d\n", cont[4]);
    printf("Reis (5): %d\n", cont[5]);
    printf("Rainhas (6): %d\n", cont[6]);

    return 0;
}
