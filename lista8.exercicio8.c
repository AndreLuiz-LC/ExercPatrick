//Ordenação
//Questão 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprime(char v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%c ", v[i]);
    printf("\n");
}

//BUBBLE
void bubbleSort(char v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                char temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

//QUICKSORT
void quickSort(char v[], int baixo, int alto) {
    if (baixo >= alto) return;

    char pivo = v[(baixo + alto) / 2];
    int i = baixo, j = alto;

    while (i <= j) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;

        if (i <= j) {
            char temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    quickSort(v, baixo, j);
    quickSort(v, i, alto);
}

//QSORT
int compara(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    char original[] = {'d', 'a', 'e', 'c', 'b'};
    int n = sizeof(original) / sizeof(original[0]);

    //Bubble Sort
    char v1[100];
    memcpy(v1, original, n);
    bubbleSort(v1, n);
    printf("Bubble Sort: ");
    imprime(v1, n);

    //Quick Sort
    char v2[100];
    memcpy(v2, original, n);
    quickSort(v2, 0, n - 1);
    printf("Quick Sort:  ");
    imprime(v2, n);

    //qsort
    char v3[100];
    memcpy(v3, original, n);
    qsort(v3, n, sizeof(char), compara);
    printf("qsort (C):   ");
    imprime(v3, n);

    return 0;
}
