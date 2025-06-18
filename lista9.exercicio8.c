#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs fornecidas no enunciado
typedef struct data {
    int dd, mm, aa; // Dia, mês, ano
} Data;

typedef struct compromisso {
    char descricao[81];
    Data dta;
} Compromisso;

// Função de busca binária por data
Compromisso* busca(int n, Compromisso** vet, int d, int m, int a) {
    int inicio = 0, fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        Data data = vet[meio]->dta;

        if (data.aa == a && data.mm == m && data.dd == d) {
            return vet[meio]; // achou
        }
        else if (
            data.aa < a || 
            (data.aa == a && data.mm < m) || 
            (data.aa == a && data.mm == m && data.dd < d)
        ) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return NULL; // não achou
}

int main() {
    int n = 3;
    Compromisso* agenda[n];

    // Compromisso 1
    agenda[0] = malloc(sizeof(Compromisso));
    strcpy(agenda[0]->descricao, "Dentista");
    agenda[0]->dta.dd = 10;
    agenda[0]->dta.mm = 6;
    agenda[0]->dta.aa = 2025;

    // Compromisso 2
    agenda[1] = malloc(sizeof(Compromisso));
    strcpy(agenda[1]->descricao, "Prova de C");
    agenda[1]->dta.dd = 15;
    agenda[1]->dta.mm = 6;
    agenda[1]->dta.aa = 2025;

    // Compromisso 3
    agenda[2] = malloc(sizeof(Compromisso));
    strcpy(agenda[2]->descricao, "Entrevista");
    agenda[2]->dta.dd = 20;
    agenda[2]->dta.mm = 6;
    agenda[2]->dta.aa = 2025;

    // Buscar por um compromisso no dia 15/06/2025
    Compromisso* resultado = busca(n, agenda, 15, 6, 2025);
    if (resultado != NULL) {
        printf("Compromisso encontrado: %s\n", resultado->descricao);
    } else {
        printf("Nenhum compromisso nesta data.\n");
    }

    // Liberar memória
    for (int i = 0; i < n; i++) {
        free(agenda[i]);
    }

    return 0;
}
