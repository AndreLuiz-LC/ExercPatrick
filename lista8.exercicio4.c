#include <stdio.h>
#include <stdlib.h>

/*4. Implemente um programa que leia do usuário vários nomes completos de pessoas,
até que o usuário digite a palavra “fim”. Esses nomes devem ser armazenados em um
vetor. Imprima no final a média e a variância do tamanho dos nomes.*/


#define MAX_NOMES 100
#define MAX_TAM 100

int main() {
    char nomes[MAX_NOMES][MAX_TAM];
    int quant = 0;
    float soma = 0.0;

    printf("Digite nomes completos (digite 'fim' para encerrar):\n");

    while (1) {
        printf("Nome %d: ", quant + 1);
        fgets(nomes[quant], MAX_TAM, stdin);

        // Remove o '\n' do final da string
        nomes[quant][strcspn(nomes[quant], "\n")] = '\0';

        if (strcmp(nomes[quant], "fim") == 0) {
            break;
        }

        soma += strlen(nomes[quant]);
        quant++;

        if (quant >= MAX_NOMES) {
            printf("Número máximo de nomes atingido.\n");
            break;
        }
    }

    if (quant == 0) {
        printf("Nenhum nome foi inserido.\n");
        return 0;
    }

    // Cálculo da média
    float media = soma / quant;

    // Cálculo da variância
    float variancia = 0.0;
    for (int i = 0; i < quant; i++) {
        int tamanho = strlen(nomes[i]);
        variancia += pow(tamanho - media, 2);
    }
    variancia /= quant;

    // Exibição dos resultados
    printf("\nTotal de nomes lidos: %d\n", quant);
    printf("Média do tamanho dos nomes: %.2f caracteres\n", media);
    printf("Variância do tamanho dos nomes: %.2f\n", variancia);

    return 0;
}
