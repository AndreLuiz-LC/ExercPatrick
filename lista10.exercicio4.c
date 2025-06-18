#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nome[100];
    printf("Digite o nome do arquivo .c: ");
    scanf("%99s", nome);

    FILE *fin = fopen(nome, "r");
    if (!fin) { printf("ERRO\n"); return 1; }

    char novo[110];
    strcpy(novo, nome);
    strcat(novo, "_sem_coment.c");

    FILE *fout = fopen(novo, "w");
    if (!fout) { printf("ERRO\n"); fclose(fin); return 1; }

    char linha[500];
    while (fgets(linha, sizeof(linha), fin)) {
        char* p = strstr(linha, "//");
        if (p) *p = '\0';
        fputs(linha, fout);
    }

    fclose(fin);
    fclose(fout);
    printf("Arquivo gerado: %s\n", novo);
    return 0;
}

