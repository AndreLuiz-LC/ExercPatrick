#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*3. Escrever um programa que declare, inicialize e imprima um vetor de 10 inteiros. O
vetor deve conter os 10 primeiros múltiplos de 5. A inicialização do vetor e a sua
impressão devem ser feitas por funções. Generalize para um vetor de n elementos.*/


void multiplos (int *vetor, int n){
    int i;
    for (i=0; i<n; i++){
    vetor[i]=(i+1)*5;
    }
}

void imprimirmultiplos (int *vetor, int n){
    printf("os %d multiplos de 5: \n", n);
    int i;
    for (i=0; i<n; i++){
    printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
   int n;
   printf("Digite quantos numeros tem o vetor: ");
   scanf("%d", &n);

   int *vetor = (int *) malloc(n * sizeof(int));
   if (vetor == NULL){
    printf("sem espaco na memoria");
   }
        multiplos(vetor, n);
        imprimirmultiplos(vetor, n);
free(vetor);

}
