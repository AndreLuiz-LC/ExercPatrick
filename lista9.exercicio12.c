#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume;   // Número de exemplares
    float preco;
} Livro;

typedef struct Biblioteca {
    Livro **V;     // vetor de ponteiros para livros
    int nLivros;   // número de livros
} Biblioteca;

// (A) Preenche e retorna um novo livro
Livro* fillLivro() {
    Livro *livro = malloc(sizeof(Livro));
    if (!livro) {
        printf("Erro de alocação.\n");
        exit(1);
    }

    printf("Digite o ano do livro: ");
    scanf("%d", &livro->ano);
    getchar(); // limpa '\n'

    printf("Digite o título do livro: ");
    fgets(livro->titulo, 100, stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(livro->autor, 100, stdin);
    livro->autor[strcspn(livro->autor, "\n")] = '\0';

    printf("Digite o número de exemplares (nVolume): ");
    scanf("%d", &livro->nVolume);

    printf("Digite o preço do livro: ");
    scanf("%f", &livro->preco);
    getchar(); // limpa '\n'

    return livro;
}

// (B) Preenche a biblioteca com numLivros livros
Biblioteca* fillBiblioteca(int numLivros) {
    Biblioteca *b = malloc(sizeof(Biblioteca));
    if (!b) {
        printf("Erro de alocação.\n");
        exit(1);
    }

    b->nLivros = numLivros;
    b->V = malloc(numLivros * sizeof(Livro*));
    if (!b->V) {
        printf("Erro de alocação vetor.\n");
        exit(1);
    }

    for (int i = 0; i < numLivros; i++) {
        printf("\nPreenchendo livro %d:\n", i + 1);
        b->V[i] = fillLivro();
    }

    return b;
}

// (C) Calcula e imprime o valor total da biblioteca
void valorBiblioteca(Biblioteca *b1, int numLivros) {
    float total = 0;

    for (int i = 0; i < numLivros; i++) {
        total += b1->V[i]->preco * b1->V[i]->nVolume;
    }

    printf("\nValor total gasto para comprar todos os exemplares: R$ %.2f\n", total);
}

// (D) Retorna o livro com maior número de exemplares
Livro* maiorBiblioteca(Biblioteca *b1, int numLivros) {
    if (numLivros == 0) return NULL;

    Livro *maior = b1->V[0];
    for (int i = 1; i < numLivros; i++) {
        if (b1->V[i]->nVolume > maior->nVolume) {
            maior = b1->V[i];
        }
    }
    return maior;
}

// (E) Programa principal
int main() {
    int n;

    printf("Digite o número de livros na biblioteca: ");
    scanf("%d", &n);
    getchar(); // limpar '\n'

    Biblioteca *b = fillBiblioteca(n);

    valorBiblioteca(b, n);

    Livro *maisExemplares = maiorBiblioteca(b, n);
    if (maisExemplares) {
        printf("\nLivro com maior número de exemplares:\n");
        printf("Título: %s\n", maisExemplares->titulo);
        printf("Autor: %s\n", maisExemplares->autor);
        printf("Ano: %d\n", maisExemplares->ano);
        printf("Número de exemplares: %d\n", maisExemplares->nVolume);
        printf("Preço: R$ %.2f\n", maisExemplares->preco);
    }

    // Liberar memória
    for (int i = 0; i < n; i++) {
        free(b->V[i]);
    }
    free(b->V);
    free(b);

    return 0;
}
