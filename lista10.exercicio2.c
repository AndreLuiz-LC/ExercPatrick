#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca(char* arquivo, char* matricula) {
    FILE* fp = fopen(arquivo, "r");
    if (!fp) {
        printf("ERRO\n");
        exit(1);
    }

    char mat[20];
    float cr;

    while (fscanf(fp, "%19s %f", mat, &cr) == 2) {
        if (strcmp(mat, matricula) == 0) {
            fclose(fp);
            return cr;
        }
    }

    fclose(fp);
    return -1.0f;
}

