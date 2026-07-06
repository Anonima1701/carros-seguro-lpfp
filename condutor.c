#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "condutor.h"
#include "linha.h"

// Cores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// cadastro do condutor
void cadastrar_condutor(Condutor *c) {
    system("clear");

    printf(ANSI_COLOR_YELLOW "\n------ Cadastro de Condutor ------\n" ANSI_COLOR_RESET);

    printf("Nome completo: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';

    // Validação do RG
    while (1) {

        printf("RG (Primeiros 5 dígitos): ");
        scanf("%s", c->rg);

        int tamanho = 0;

        while (c->rg[tamanho] != '\0')
            tamanho++;

        if (tamanho == 5) {

            int ok = 1;

            for (int i = 0; i < 5; i++) {

                if (c->rg[i] < '0' || c->rg[i] > '9') {
                    ok = 0;
                    break;
                }

            }

            if (ok)
                break;
        }

        printf(ANSI_COLOR_RED "Erro: O RG deve ter exatamente 5 numeros.\n" ANSI_COLOR_RESET);
    }

    // Validacão da idade
    while (1) {
        printf("Idade: ");
        if (scanf("%d", &c->idade) == 1 && c->idade >= 18 && c->idade <= 75) {
            break;
        }
        printf(ANSI_COLOR_RED "Erro: Idade inválida (deve ser maior de 18 anos).\n" ANSI_COLOR_RESET);
    }

    // Validação dos sinistros
    while (1) {
        printf("Número de sinistros (últimos 3 anos): ");
        if (scanf("%d", &c->sinistros) == 1 && c->sinistros >= 0) {
            break;
        }
        printf(ANSI_COLOR_RED "Erro: Quantidade inválida.\n" ANSI_COLOR_RESET);
    }


    // Validação da cnh
    while (1) {

        printf("Categoria da CNH (A, B ou C): ");
        scanf(" %c", &c->cnh);

        if (c->cnh == 'a') {
            c->cnh = 'A';
        }
        else if (c->cnh == 'b') {
            c->cnh = 'B';
        }
        else if (c->cnh == 'c') {
            c->cnh = 'C';
        }

        if (c->cnh == 'A' || c->cnh == 'B' || c->cnh == 'C') {
            break;
        }

        printf(ANSI_COLOR_RED "Erro: Categoria inválida. Escolha A, B ou C.\n" ANSI_COLOR_RESET);
    }
    printf(ANSI_COLOR_GREEN "\n-> Condutor cadastrado com sucesso\n" ANSI_COLOR_RESET);
}
// exibição do condutor
void exibir_condutor(Condutor *c) {
    system("clear");

    printf(ANSI_COLOR_YELLOW "\n------ Informações do Condutor ------\n" ANSI_COLOR_RESET);
    printf("Nome: %s\n", c->nome);
    printf("RG: %s\n", c->rg);
    printf("Idade: %d anos\n", c->idade);
    printf("Sinistros: %d\n", c->sinistros);
    printf("CNH: %c\n", c->cnh);

    pausar();
}