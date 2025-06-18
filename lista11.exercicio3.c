#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() 
{   
    Aluno *lista = NULL; //inicializar a lista

    lista = incluir(lista, "João", 1, 20);
    lista = incluir(lista, "Maria", 2, 21);
    lista = incluir(lista, "Carlos", 3, 22);

    printf("Alunos:\n");
    imprime(lista);

    alterarAluno(lista, 2, "Maria Roberta", 25);
    imprime(lista);

    lista = excluirAluno(lista, 1);
    imprime(lista);

    return 0;
}

