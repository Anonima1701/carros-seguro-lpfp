#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "condutor.h"

// cadastro do condutor
void cadastrar_condutor(Condutor *c) {
    system("clear");

    printf("\n------ Cadastro de Condutor ------\n");

    printf("Nome completo: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';

    // Validação do RG
    while (1) {

        printf("RG (Primeiros 5 digitos): ");
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

        printf("Erro: O RG deve ter exatamente 5 numeros.\n");
    }

    // Validacão da idade
    while (1) {
        printf("Idade: ");
        if (scanf("%d", &c->idade) == 1 && c->idade >= 18 && c->idade <= 75) {
            break;
        }
        printf("Erro: Idade invalida (deve ser maior de 18).\n");
    }

    // Validação dos sinistros
    while (1) {
        printf("Numero de sinistros (ultimos 3 anos): ");
        if (scanf("%d", &c->sinistros) == 1 && c->sinistros >= 0) {
            break;
        }
        printf("Erro: Quantidade invalida.\n");
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

        printf("Erro: Categoria invalida. Escolha A, B ou C.\n");
    }
}
// exibição do condutor
void exibir_condutor(Condutor *c) {
    system("clear");

    printf("\n------ Informações do Condutor ------\n");
    printf("Nome: %s\n", c->nome);
    printf("RG: %s\n", c->rg);
    printf("Idade: %d anos\n", c->idade);
    printf("Sinistros: %d\n", c->sinistros);
    printf("CNH: %c\n", c->cnh);
}
