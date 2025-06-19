//Questão 7
#include <stdio.h>
//a)Distância entre duas cidades

int main() {
    int dist[5][5] = {
        {0, 15, 30, 5, 12},
        {15, 0, 10, 17, 28},
        {30, 10, 0, 3, 11},
        {5, 17, 3, 0, 80},
        {12, 28, 11, 80, 0}
    };

    int origem, destino;

    while (1) {
        printf("Informe duas cidades (1 a 5) ou 0 0 para sair: ");
        scanf("%d %d", &origem, &destino);

        if (origem == 0 && destino == 0)
            break;

        if (origem < 1 || origem > 5 || destino < 1 || destino > 5) {
            printf("Cidades inválidas! Digite valores entre 1 e 5.\n");
            continue;
        }

        printf("Distância entre cidade %d e cidade %d: %d km\n",
               origem, destino, dist[origem - 1][destino - 1]);
    }

    return 0;
}
*/

//b)Imprimir a tabela sem repetições

int main() {
    int dist[5][5] = {
        {0, 15, 30, 5, 12},
        {15, 0, 10, 17, 28},
        {30, 10, 0, 3, 11},
        {5, 17, 3, 0, 80},
        {12, 28, 11, 80, 0}
    };

    printf("Tabela de distâncias (sem repetições):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            printf("Cidade %d <-> Cidade %d: %d km\n", i + 1, j + 1, dist[i][j]);
        }
    }

    return 0;
}
*/

//c)Total de um percurso

int main() {
    int dist[5][5] = {
        {0, 15, 30, 5, 12},
        {15, 0, 10, 17, 28},
        {30, 10, 0, 3, 11},
        {5, 17, 3, 0, 80},
        {12, 28, 11, 80, 0}
    };

    int percurso[100], n = 0, total = 0;

    printf("Informe o percurso (cidades de 1 a 5), termine com 0:\n");

    while (1) {
        scanf("%d", &percurso[n]);
        if (percurso[n] == 0) break;
        if (percurso[n] < 1 || percurso[n] > 5) {
            printf("Cidade inválida. Digite valores entre 1 e 5.\n");
            continue;
        }
        n++;
    }

    for (int i = 0; i < n - 1; i++) {
        int origem = percurso[i] - 1;
        int destino = percurso[i + 1] - 1;
        total += dist[origem][destino];
    }

    printf("Distância total percorrida: %d km\n", total);

    return 0;
}
