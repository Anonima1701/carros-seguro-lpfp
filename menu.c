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
        system("clear");
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
        printf(ANSI_COLOR_GREEN "Digite sua escolha: "ANSI_COLOR_RESET);

        if (scanf("%d", &op) != 1) {
            system("clear");
            printf(ANSI_COLOR_RED "Digite apenas números!\n" ANSI_COLOR_RESET);
            while (getchar() != '\n');
            op = -1;
            continue;
        }
        while (getchar() != '\n');

        switch (op) {
        case 1:
            system("clear");
            cadastrarVeiculo(v);
            temVeiculo = 1;
            break;

        case 2:
            system("clear");
            exibirVeiculo(v);
            break;

        case 3:
            system("clear");
            cadastrar_condutor(c);
            temCondutor = 1;
            break;

        case 4:
            system("clear");
            exibir_condutor(c);
            break;

        case 5:
            if (!temVeiculo || !temCondutor) {
                system("clear");
                printf(ANSI_COLOR_RED "\n-> Cadastre primeiro o veículo e o condutor.\n" ANSI_COLOR_RESET);
                break;
            }

            nova.veiculo = *v;
            nova.condutor = *c;

            calcCotacao(&nova);

            if (adicionarCotacao(lista, total, nova) && SalvarArquivo(&nova)) {
                system("clear");

                printf(ANSI_COLOR_GREEN "Cotação salva com sucesso!\n" ANSI_COLOR_RESET);
                printf("Prêmio anual: R$ %.2f\n", nova.premio_anual);
                printf("Prêmio mensal: R$ %.2f\n", nova.premio_mensal);
            } else {
                system("clear");

                printf(ANSI_COLOR_RED "Erro ao salvar cotação.\n" ANSI_COLOR_RESET);
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
        system("clear");
        linha();
        printf(ANSI_COLOR_GREEN "         Menu de Relatórios        \n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "1. Listar todas as cotações\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "2. Filtrar por nome do condutor\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "3. Exibir menor cotação\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_RED "4. Voltar\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_GREEN "Digite sua escolha: " ANSI_COLOR_RESET);

        if (scanf("%d", &op) != 1) {
            system("clear");
            printf(ANSI_COLOR_RED "Digite apenas números!\n" ANSI_COLOR_RESET);
            while (getchar() != '\n');
            op = -1;
            continue;
        }
        while (getchar() != '\n');

        switch (op) {
        case 1:
            system("clear");
            Listar_cotacoes(lista, total);
            pausar();
            break;

        case 2:
            system("clear");
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
            system("clear");
            menor_cotacao(lista, total);
            pausar();
            break;

        case 4:
            system("clear");
            printf(ANSI_COLOR_YELLOW "\n-> Voltando ao menu principal" ANSI_COLOR_RESET);
            break;
        default:
            system("clear");
            printf(ANSI_COLOR_RED "\n[Aviso] Opção incorreta! Tente novamente.\n" ANSI_COLOR_RESET);
        }
    } while (op != 4);
}