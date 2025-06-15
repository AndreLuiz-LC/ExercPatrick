#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*6. Considere que você digitou o seu nome para o programa abaixo. O que será impresso?
Indique o que você digitou. Justifique sua resposta. (não vale ponto para apresentação)

#define MAX 50

int main (void) {
char texto[MAX +2], temp ;
int tam , i;
gets( texto );
tam = strlen(texto);
for (i = 0; i < tam ; i ++) {
temp = texto[i];
texto[i] = texto[ tam -1 - i ];
texto[strlen(texto) -1 - i] = temp ;
}
puts ( texto );
return 0;
}
 DIGITEI MEU NOME E SAIU MEU NOME

*/
