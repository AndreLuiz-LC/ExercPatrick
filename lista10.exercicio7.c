#include <stdio.h>
#include <stdlib.h>

int cmpf(const void *a, const void *b) {
    float fa = *(float*)a;
    float fb = *(float*)b;
    return (fa > fb) - (fa < fb);
}

int main() {
    FILE *fin = fopen("numeros.txt", "r");
    if (!fin) { printf("ERRO\n"); return 1; }

    float *v = NULL, x;
    size_t n = 0;

    while (fscanf(fin, "%f", &x) == 1) {
        float *t = realloc(v, (n+1)*sizeof(float));
        if (!t) { printf("ERRO\n"); free(v); fclose(fin); return 1; }
        v = t; v[n++] = x;
    }
    fclose(fin);

    qsort(v, n, sizeof(float), cmpf);

    FILE *fout = fopen("numeros.bin", "wb");
    if (!fout) { printf("ERRO\n"); free(v); return 1; }

    fwrite(v, sizeof(float), n, fout);
    fclose(fout);
    free(v);

    printf("Dados gravados em numeros.bin\n");
    return 0;
}

