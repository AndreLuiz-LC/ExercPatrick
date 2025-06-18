#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(char* mat, char* nome_arquivo) {
    FILE* fp = fopen(nome_arquivo, "r");
    if (!fp) {
        printf("ERRO\n");
        exit(1);
    }

    char mat_arq[20];
    float p1, p2, p3;

    while (fscanf(fp, "%19s %f %f %f", mat_arq, &p1, &p2, &p3) == 4) {
        if (strcmp(mat, mat_arq) == 0) {
            fclose(fp);
            return (p1 + p2 + p3) / 3.0f;
        }
    }

    fclose(fp);
    return -1.0f;
}

