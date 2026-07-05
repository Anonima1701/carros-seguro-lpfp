#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "veiculo.h"
#include "condutor.h"
#include "cotacao.h"
#include "arquivo.h"
#include "relatorio.h"
#include "linha.h"

// Cores
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"


void menuCadastro(Veiculo *v, Condutor *c, Cotacao **lista, int *total) {
    int op;
    int temVeiculo = 0;
    int temCondutor = 0;
    Cotacao nova;
    
    do {
        linha();
        printf(ANSI_COLOR_GREEN "         Menu de Cadastro        \n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "1. Cadastrar veículo\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "2. Exibir veículo cadastrado\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "3. Cadastrar condutor\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "4. Exibir condutor cadastrado\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "5. Calcular cotações \n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_RED "6. Voltar\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_GREEN "Escreva sua escolha: "ANSI_COLOR_RESET);

        if (scanf("%d", &op) != 1) {
            system("clear");
            printf("Digite apenas numeros!\n");
            while (getchar() != '\n');
            op = -1;
            continue;
        }
        while (getchar() != '\n');

        switch (op) {
        case 1:
            cadastrarVeiculo(v);
            temVeiculo = 1;
            break;

        case 2:
            exibirVeiculo(v);
            break;

        case 3:
            cadastrar_condutor(c);
            temCondutor = 1;
            break;

        case 4:
            exibir_condutor(c);
            break;

        case 5:
            if (!temVeiculo || !temCondutor) {
                system("clear");
                printf(ANSI_COLOR_RED "\n-> Cadastre primeiro o veiculo e o condutor.\n" ANSI_COLOR_RESET);
                break;
            }

            nova.veiculo = *v;
            nova.condutor = *c;

            calcCotacao(&nova);

            if (adicionarCotacao(lista, total, nova) && SalvarArquivo(&nova)) {
                system("clear");

                printf(ANSI_COLOR_GREEN "Cotacao salva com sucesso!\n" ANSI_COLOR_RESET);
                printf("Premio anual: R$ %.2f\n", nova.premio_anual);
                printf("Premio mensal: R$ %.2f\n", nova.premio_mensal);
            } else {
                system("clear");

                printf(ANSI_COLOR_RED "Erro ao salvar cotacao.\n" ANSI_COLOR_RESET);
            }

            pausar();
            break;

        case 6:
            system("clear");
            printf(ANSI_COLOR_YELLOW "\n-> Voltando ao menu principal" ANSI_COLOR_RESET);
            break;

        default:
            system("clear");
            printf(ANSI_COLOR_RED "\n[Aviso] Opção incorreta! Tente novamente.\n" ANSI_COLOR_RESET);
        }
    }  while (op != 6);
}

void menuRelatorio (Cotacao *lista, int total) {
    int op;
    char nome[80];

    do {
        // Menu de Relatorios
        linha();
        printf(ANSI_COLOR_GREEN "         Menu de Relatorios        \n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "1. Listar todas as cotacoes\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "2. Filtrar por nome do condutor\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "3. Exibir menor cotacao\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_RED "4. Voltar\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_GREEN "Escreva sua escolha: " ANSI_COLOR_RESET);

        if (scanf("%d", &op) != 1) {
            system("clear");
            printf(ANSI_COLOR_RED "Digite apenas numeros!\n" ANSI_COLOR_RESET);
            while (getchar() != '\n');
            op = -1;
            continue;
        }
        while (getchar() != '\n');

        switch (op) {
        case 1:
            Listar_cotacoes(lista, total);
            pausar();
            break;

        case 2:
            printf("Nome do condutor: ");
            fgets(nome, sizeof(nome), stdin);

            int i = 0;
            while (nome[i] != '\n' && nome[i] != '\0') {
                i++;
            }
            nome[i] = '\0';

            filtrar_por_condutor(lista, total, nome);
            pausar();
            break;

        case 3:
            menor_cotacao(lista, total);
            pausar();
            break;

        case 4:
            system("clear");
            printf(ANSI_COLOR_YELLOW "\n-> Voltando ao menu principal" ANSI_COLOR_RESET);
            break;
        default:
            system("clear");
            printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
        }
    } while (op != 4);
}