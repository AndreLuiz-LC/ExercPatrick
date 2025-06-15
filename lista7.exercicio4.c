#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*4. Escreva um programa para declarar um vetor de caracteres de tamanho 26 e imprimir o
seu conteúdo. O vetor deve ser inicializado com as letras minúsculas do alfabeto. A
inicialização do vetor e a sua impressão devem ser feitas por funções.*/

void iniciarstr(char frase[]){
    int i;
    for(i=0; i<26; i++){ //coloquei 27 porque ultimo indice da string e "\0" //
            frase[i]='a' + 1;
    }
    frase[26]= '\0';
}

void imprimirstr (char frase[], int n){
    printf("letras minusculas do alfabeto:\n");
    int i;
    for (i=0; i<n; i++){
            printf("%c", frase[i]);
    }
    printf("\n");
}

int main (){
    char frase[26];

    iniciarstr(frase);
    imprimirstr(frase, 27);
}
