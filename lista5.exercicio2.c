#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//2. Mostre e explique (comentando as linhas de código) o que será impresso na tela://

int main(void) // comando para inicializar o codigo principal. No slide estava sem "int" foi atribuido para nao dar erro//
{
char texto[]= "foi muito facil"; // criando uma variavel string como vetor de ate 15 caracteres//
int i; // criando uma variavel vazia para ser atribuido cada elemento do vetor//
for (i = 0; texto[i]!='\0'; i++) // criando um for para ler os caracteres que sejam diferentes do \0 que seria o ultimo//
{
if (texto[i] == ' ') break; // usando if dentro do for para a repeticao parar quando encontrar espaço//
}
i++; // adicionando os caracteres que estaram da string //
for ( ; texto[i]!='\0'; i++) // lendo os caracteres e adicionando a um novo vetor //
{
printf("%c", texto[i]); // vai imprimir a string sem a primeira palavra, que ficou retida na primeira repeticao //
}
}


