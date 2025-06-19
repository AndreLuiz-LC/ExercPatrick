#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*12. Fazer um programa para receber uma string do usuário (máx. 50 caracteres) e fazer uma
estatística dos caracteres digitados. Por exemplo, para a string "O EXERCICIO E FACIL"”, a
estatística mostrada será 'O' = 2, ' '=3, 'E' = 3, 'X' = 1, 'R' = 1, 'C' = 3, 'I' = 3, 'F' = 1, 'A' = 1, 'L' = 1*/

int main(){
char frase[51]; //determinando o tamanho da string, ate 51 pq o ultimo e sempre ("/0")//
int contagem[256]={0}; //vetor para contar a frequencia dos indices da string//
int i; //variavel vazia para fazer a contagem dos caracteres//
printf("Escreva uma frase: \n");
fgets(frase, sizeof(frase), stdin); //funcao fgets, funcao para ler uma string//
for (i=0; frase[i] != '/0'; i++){ //para nao contar o ultimo indice usei ma tomada de decisao//
        if (frase[i] != ' ')// para nao contar os espacos//
        contagem[(unsigned char)frase[i]]++;//vai contanto todos os caracteres da string//
}

//para imprimir a contagem feita//
for (i=0; i<256; i++){
    if (contagem[i] != 0){ //nao contar os que nao teve enenhuma soma//
        printf("'%c' = %d\n", i, contagem[i]); //transforma os char em inteiros e faz a contagem//
}
}
}
