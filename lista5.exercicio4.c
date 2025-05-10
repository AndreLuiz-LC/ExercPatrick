#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*4. Escreva um programa em C para ler uma palavra e escrever:
-A primeira letra da palavra.
-A última letra da palavra.
-O número de letras existente na palavra (não usar a função strlen())*/

int main (){
char palavra[100];
printf("escreva uma palavra: ");
scanf("%s", palavra);
int tamanho=0;
int i=0;
while (palavra[i] != '\0'; i++, tamanho++)


printf("A primeira letra da palavra e: %c\n", palavra[0]);
printf("A ultima letra da palavra e: %c\n", palavra[tamanho-1]);
printf("O numero de letras que contem na palavra e de: %d\n", tamanho);
}
