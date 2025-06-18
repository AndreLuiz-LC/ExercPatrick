#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    char nome[81];
    float valor_hora;
    int horas_mes;
} Funcionario;

void carrega(int n, Funcionario** vet, char* arquivo) {
    FILE* fp = fopen(arquivo, "r");
    if (!fp) {
        printf("ERRO\n");
        exit(1);
    }

    char buffer[200];
    int count = 0;
    while (count < n && fgets(buffer, sizeof(buffer), fp)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n')
            buffer[len-1] = '\0';

        Funcionario* f = malloc(sizeof(Funcionario));
        strcpy(f->nome, buffer);

        if (fscanf(fp, "%f %d", &f->valor_hora, &f->horas_mes) != 2) {
            free(f);
            break;
        }

        vet[count] = f;
        count++;
        fgets(buffer, sizeof(buffer), fp);
    }

    fclose(fp);
}

