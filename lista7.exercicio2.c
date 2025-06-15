#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//2. O que será impresso na tela? Mostre o andamento da execução.//


int main (void) {
char *frase = "Otimo teste"; //criando uma string//
char *p , misterio[80]; //definindo o numero de caractere dessa string//
int i = 0; //criando uma variavel vazia para fazer a troca com os indices da string//
int j = 0; //mesma da anterior//
p = frase + strlen ( frase ) - 1; //inicializando o ponteiro//
while (*p != ' ') { //fazendo um while para percorrer a string, apenas com os caracteres pulando espaços//
    misterio[i] = *p; //percorrendo a string e atribuindo o indice ao ponteiro//
    i ++; p --; //enquanto a repeticao sobe de 1 a 1 na string, pelo ponteiro diminui o numero de repeticao//
    }
misterio[i] = ' '; i ++;//caso encontre um espaco pular para o proximo//
while ( frase[j] != ' ') { //comecando repeticao do indice 0 que foi o valor atribuido a j//
misterio [i] = frase[j];//indice de misterio substituido pelo de frase//
j ++; i ++; //subindo indices de um a um//
}
misterio[i] = '\0 '; //quando se cria uma string o ultimo indice sempre sera "\0" //
puts (misterio);
return 0;
}

//RESPOSTA DA IMPRESSAO: teste rapido//
