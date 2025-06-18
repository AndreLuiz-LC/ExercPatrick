#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[81];
    float nota1, nota2;
} ALUNO;

void listar_media6(FILE* f) {
    rewind(f);
    ALUNO a;
    while (fread(&a, sizeof(ALUNO), 1, f) == 1) {
        if ((a.nota1 + a.nota2) / 2.0 >= 6.0)
            printf("%s -> %.2f\n", a.nome, (a.nota1 + a.nota2)/2.0);
    }
}

void incluir(FILE* f) {
    ALUNO a;
    printf("Nome: ");
    fgets(a.nome, 81, stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0';
    printf("Nota1, Nota2: ");
    scanf("%f %f", &a.nota1, &a.nota2);
    fseek(f, 0, SEEK_END);
    fwrite(&a, sizeof(ALUNO), 1, f);
    getchar();
}

void alterar(FILE* f) {
    char busca[81];
    printf("Nome a alterar: ");
    fgets(busca,81,stdin); busca[strcspn(busca,"\n")]=0;
    ALUNO a;
    rewind(f);
    long pos;
    while ((pos = ftell(f)), fread(&a, sizeof(ALUNO), 1, f) == 1) {
        if (strcmp(a.nome, busca) == 0) {
            printf("Novas notas: ");
            scanf("%f %f", &a.nota1, &a.nota2);
            fseek(f, pos, SEEK_SET);
            fwrite(&a, sizeof(ALUNO), 1, f);
            getchar();
            return;
        }
    }
    printf("Aluno nao encontrado.\n");
    getchar();
}

void excluir(FILE* f) {
    printf("Função excluir não implementada.\n");
}

void consultar(FILE* f) {
    char busca[81];
    printf("Nome a consultar: ");
    fgets(busca,81,stdin); busca[strcspn(busca,"\n")]=0;
    ALUNO a;
    rewind(f);
    while (fread(&a, sizeof(ALUNO), 1, f) == 1) {
        if (strcmp(a.nome, busca) == 0) {
            printf("%s -> %.2f, %.2f\n", a.nome, a.nota1, a.nota2);
            return;
        }
    }
    printf("Aluno nao encontrado.\n");
}

int main() {
    FILE* f = fopen("alunos.bin", "r+b");
    if (!f) f = fopen("alunos.bin", "w+b");
    if (!f) { printf("ERRO\n"); return 1; }

    int opt;
    do {
        printf("\n1-Incluir 2-Alterar 3-Consultar 4-Listar>=6.0 5-Sair\nOpção: ");
        scanf("%d", &opt);
        getchar();
        switch(opt) {
            case 1: incluir(f); break;
            case 2: alterar(f); break;
            case 3: consultar(f); break;
            case 4: listar_media6(f); break;
            case 5: break;
            default: printf("Opção inválida.\n");
        }
    } while(opt != 5);

    fclose(f);
    return 0;
}

