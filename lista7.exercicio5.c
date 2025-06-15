#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*5. Escreva um programa que leia uma linha de caracteres do teclado de tamanho 80. A
linha somente contém letras. Divida a linha em blocos de 5 letras. Dentro de cada bloco o
seu programa deve trocar a primeira letra pela letra seguinte no alfabeto, a segunda letra
por duas letras adiante no alfabeto, a terceira por três letras adiante e assim até a quinta.
Os espaços em branco devem ser retirados da frase. Considere o seguinte exemplo.*/



// Remove espaços da frase
void removerEspacos(char origem[], char destino[]) {
    int j = 0;
    for (int i = 0; origem[i] != '\0'; i++) {
        if (origem[i] != ' ') {
            destino[j++] = toupper(origem[i]); // Coloca em maiúscula
        }
    }
    destino[j] = '\0'; // finaliza string
}

// Criptografa a frase em blocos de 5 letras
void criptografar(char entrada[], char saida[]) {
    int len = strlen(entrada);
    int j = 0;

    for (int i = 0; i + 4 < len; i += 5) {  // somente blocos completos
        for (int k = 0; k < 5; k++) {
            char letra = entrada[i + k];
            letra = ((letra - 'A' + (k + 1)) % 26) + 'A';  // desloca e trata volta ao início do alfabeto
            saida[j++] = letra;
        }
    }
    saida[j] = '\0';
}

int main() {
    char linha[81];        // entrada original
    char semEspacos[81];   // frase sem espaços
    char criptografada[81];

    printf("Digite uma linha (máx. 80 letras):\n");
    fgets(linha, sizeof(linha), stdin);

    // Remove nova linha final se houver
    linha[strcspn(linha, "\n")] = '\0';

    removerEspacos(linha, semEspacos);
    criptografar(semEspacos, criptografada);

    printf("Frase criptografada:\n%s\n", criptografada);

    return 0;
}
