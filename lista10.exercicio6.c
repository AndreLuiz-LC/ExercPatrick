#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        char nome[20];
        sprintf(nome, "teste%02d.txt", i);
        FILE* fp = fopen(nome, "w");
        if (!fp) { printf("ERRO criando %s\n", nome); return 1; }
        fprintf(fp, "Texto do arquivo %02d\n", i);
        fclose(fp);
    }
    printf("Arquivos gerados.\n");
    return 0;
}

