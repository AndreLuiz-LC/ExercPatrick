#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/* 10. Fazer um programa para cadastro e di�logo de login. O programa deve:
a. Cadastrar um nome de usu�rio via teclado. O nome de usu�rio tem, no m�ximo, 8 caracteres,
sendo v�lidos somente os caracteres num�ricos e as letras mai�sculas ou min�sculas. Somente os
caracteres v�lidos devem ser exibidos no console durante a digita��o do nome de usu�rio.
b. Cadastrar uma senha do usu�rio via teclado. Esta segue as mesmas regras do nome de usu�rio,
com a diferen�a de que s�o exibidos somente asteriscos no console � medida que a senha � digitada.
c. Receber um novo nome de usu�rio e uma nova senha, utilizando os mesmos procedimentos
descritos nos itens a e b.
d. Comparar o nome de usu�rio cadastrado com o recebido posteriormente e a senha cadastrada
com a senha recebida. Caso sejam id�nticos, informar �OK�, do contr�rio, informar �Acesso
negado�.*/


void verificarentrada (char entrada[], int naomostrar){
char verificar;
int i=0;
while (i<8){
    verificar=getch();
    if (verificar == '\r'){
        break;
    }
    if (isalnum(verificar)){
        entrada[i++] = verificar;
        if (naomostrar);
        printf("*");
    }
        else{
            printf("%c", verificar);
    }
}
entrada[i] = '\0';
printf("\n");
}

int main (){
char nome_do_usuario [9]; //colocando 9 posicoes porque a ultima e o "/0" //
char senha [9];
char nome_digitado [9];
char senha2 [9];

//analisando login//

printf("Cadastro\n");
printf("Digite o login contendo apenas letras e numeros de ate 8 caracteres: \n");
verificarentrada(nome_do_usuario, 0);

//pedindo a senha//

printf ("Digite a senha co letras e numeros de ate 8 caracteres \n");
verificarentrada(senha, 1);

//pedindo o login da pessoa//

printf("Login:\n");
printf("Digite o seu login: \n");
verificarentrada(nome_digitado,0);

//confirmando a senha//

printf("digite sua senha: \n");
verificarentrada(senha2, 1);

//coparar se as strings sao iguais//

if (strcmp(nome_do_usuario, nome_digitado)==0){
    printf("seu login esta correto. \n");
    }
    else{
        printf("Login diferente do cadastrado \n");
    }
if (strcmp(senha, senha2) == 0)
    {
    printf("Senha esta correta \n");
}
else {
    printf("Senha incorreta \n");
}
}







