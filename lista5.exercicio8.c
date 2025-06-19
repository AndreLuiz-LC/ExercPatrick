#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*08.Faça um programa que dado 2 palavras, determine:
a. Se as palavras são iguais;
b. Verifique se a segunda palavra é uma sub string da primeira. Ex: casa e casamento.*/

int main (){
char primeirapalavra [100];
char segundapalavra[100];
printf("digite a primeira palavra: \n");
scanf("%s", primeirapalavra);
printf("digite a segunda palavra: \n");
scanf("%s", segundapalavra);
if (strcmp(primeirapalavra, segundapalavra) == 0){ //funcao strcmp compara as strings, slide 07 "strings" classroom//
    printf("As palavras sao iuais\n");
}
else {
    printf("As palavras nao sao iguais\n");
}
if (strstr(primeirapalavra, segundapalavra) == NULL){
    printf ("Essa palavra e substring da outra \n");
}
else{
    printf("Essa palavra nao e substring da outra \n");
}
}


