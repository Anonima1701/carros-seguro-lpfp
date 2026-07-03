#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "condutor.h"

// Função para limpar a sujeira do buffer do teclado
void flush_in() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
} 

void cadastrar_condutor(Condutor *c) {
    printf("\n--- CADASTRO DE CONDUTOR ---\n");

    printf("Nome completo: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';

    // Validação do RG
    while (1) {
        printf("RG (5 digitos): ");
        fgets(c->rg, sizeof(c->rg), stdin);
        c->rg[strcspn(c->rg, "\n")] = '\0';

        if (strlen(c->rg) == 5) {
            int ok = 1;
            for (int i = 0; i < 5; i++) {
                if (!isdigit(c->rg[i])) {
                    ok = 0;
                    break;
                }
            }
            if (ok) break;
        }
        printf("Erro: O RG deve ter exatamente 5 numeros. Tente novamente.\n");
    }

    // Validação da idade
    while (1) {
        printf("Idade: ");
        if (scanf("%d", &c->idade) == 1 && c->idade >= 18 && c->idade <= 120) {
            break;
        }
        printf("Erro: Idade invalida (deve ser maior de 18).\n");
        flush_in();
    }

    // Validação dos sinistros
    while (1) {
        printf("Numero de sinistros (ultimos 3 anos): ");
        if (scanf("%d", &c->sinistros) == 1 && c->sinistros >= 0) {
            break;
        }
        printf("Erro: Quantidade invalida.\n");
        flush_in();
    }

    flush_in();

    // Validação da cnh
    while (1) {
        printf("Categoria da CNH (A, B ou C): ");
        scanf("%c", &c->cnh);
        flush_in();

        c->cnh = toupper(c->cnh);

        if (c->cnh == 'A' || c->cnh == 'B' || c->cnh == 'C') {
            break;
        }
        printf("Erro: Categoria invalida. Escolha A, B ou C.\n");
    }
}

void exibir_condutor(Condutor *c) {
    system("clear");

    printf("\n---------------------------------\n");
    printf("Nome: %s\n", c->nome);
    printf("RG: %s\n", c->rg);
    printf("Idade: %d anos\n", c->idade);
    printf("Sinistros: %d\n", c->sinistros);
    printf("CNH: %c\n", c->cnh);
    printf("---------------------------------\n");

    pausar();
}
