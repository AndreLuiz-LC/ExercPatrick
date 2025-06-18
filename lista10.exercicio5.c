#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[100];
    printf("Digite nome do arquivo: ");
    scanf("%99s", nome);

    FILE* fp = fopen(nome, "r");
    if (!fp) { printf("ERRO\n"); return 1; }

    float *v = NULL, x;
    size_t n = 0;
    float soma = 0.0f;

    while (fscanf(fp, "%f", &x) == 1) {
        float *tmp = realloc(v, (n+1) * sizeof(float));
        if (!tmp) { printf("ERRO\n"); free(v); fclose(fp); return 1; }
        v = tmp;
        v[n++] = x;
        soma += x;
    }

    fclose(fp);

    if (n > 0)
        printf("Média: %.2f\n", soma / n);
    else
        printf("Nenhum número lido.\n");

    free(v);
    return 0;
}

