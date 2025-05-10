#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char*str){
int i, j;
char temp;
int tamanho = strlen(str);
for (i=0, j=tamanho-1; i<j; i++, j--){
    temp=str[i];
    str[i]=str[j];
    str[j]=temp;
    }

}

int main() {
    char str[100];
    printf("Digite a palavra: ");
    scanf("%99s", str);
    inverte(str);
    printf("Palavra invertida: %s\n", str);
}
