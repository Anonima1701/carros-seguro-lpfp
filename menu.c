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

void menuCadastro(Veiculo *v, Condutor *c, Cotacao **lista, int *total) {
    int op;
    int temVeiculo = 0;
    int temCondutor = 0;
    Cotacao nova;

    do {
    system("clear");

        linha();
        printf("         Menu de Cadastro        \n");
        linha();
        printf("1. Cadastrar veículo\n");
        linha();
        printf("2. Exibir veículo cadastrado\n");
        linha();
        printf("3. Cadastrar condutor\n");
        linha();
        printf("4. Exibir condutores cadastrados\n");
        linha();
        printf("5. Calcular cotações \n");
        linha();
        printf("6. Voltar\n");
        linha();
        printf("Digite sua escolha: ");

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
                printf("\n-> Cadastre primeiro o veículo e o condutor.\n");
                break;
            }

            nova.veiculo = *v;
            nova.condutor = *c;

            calcCotacao(&nova);

            if (adicionarCotacao(lista, total, nova) && SalvarArquivo(&nova)) {
                system("clear");

                printf("Cotação salva com sucesso!\n");
                printf("Prêmio anual: R$ %.2f\n", nova.premio_anual);
                printf("Prêmio mensal: R$ %.2f\n", nova.premio_mensal);
            } else {
                system("clear");

                printf("Erro ao salvar cotação.\n");
            }

            pausar();
            break;

        case 6:
            system("clear");
            printf("\n-> Voltando ao menu principal");
            break;

        default:
            system("clear");
            printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
        }
    }  while (op != 6);
}

void menuRelatorio (Cotacao *lista, int total) {
    int op;
    char nome[80];

    do {
    system("clear");

        linha();
        printf("         Menu de Relatórios        \n");
        linha();
        printf("1. Listar todas as cotações\n");
        linha();
        printf("2. Filtrar por nome do condutor\n");
        linha();
        printf("3. Exibir menor cotação\n");
        linha();
        printf("4. Voltar\n");
        linha();
        printf("Digite sua escolha: ");

        if (scanf("%d", &op) != 1) {
            system("clear");
            printf("Digite apenas números!\n");
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
            printf("\n-> Voltando ao menu principal");
            break;
        default:
            system("clear");
            printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
        }
    } while (op != 4);
}