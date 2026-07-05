#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "veiculo.h"
#include "arquivo.h"
#include "relatorio.h"
#include "condutor.h"
#include "cotacao.h"
#include "menu.h"
#include "linha.h"

// Cores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//Função principal
int main() {
    setlocale(LC_ALL, ""); //para ser aceito caracteres especiais.

    //Variaveis
    Veiculo v;
    Condutor c;
    Cotacao *lista = NULL;
    int total = 0;
    int escolha = 0;

    //carregar cotações
    Listar_cotacoes(lista, total);
    total = CarregarArquivo(&lista);

    system("clear");

    do {
        // Estrutura do Menu
        linha();
        printf(ANSI_COLOR_GREEN "         Menu Principal        \n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "1. Cadastro (Veiculo,condutor e calculo de premio)\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_YELLOW "2. Relatorios\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_RED "3. Exit\n" ANSI_COLOR_RESET);
        linha();
        printf(ANSI_COLOR_GREEN "Escreva sua escolha: "ANSI_COLOR_RESET);

        // Verificação de escolha
        if (scanf("%d", &escolha) != 1) {
            printf(ANSI_COLOR_RED "Digite apenas numeros!\n" ANSI_COLOR_RESET);
            while (getchar() != '\n');
            escolha = -1;
        }

        // Opções a serem usadas
        switch (escolha) {
        case 1:
            system("clear");
            printf(ANSI_COLOR_YELLOW "\n-> Abrindo Menu de Cadastro\n" ANSI_COLOR_RESET);
            menuCadastro(&v, &c, &lista, &total);
            break;

        case 2 :
            system("clear");
            printf(ANSI_COLOR_YELLOW "\n-> Abrindo Menu de Relatórios\n" ANSI_COLOR_RESET);
            menuRelatorio(lista, total);
            break;

        case 3:
            system("clear");
            printf(ANSI_COLOR_YELLOW "\n-> Finalizando tarefa!\n" ANSI_COLOR_RESET);
            break;

        default:
            system("clear");
            printf(ANSI_COLOR_RED "\n[Aviso] Opção incorreta! Tente novamente.\n" ANSI_COLOR_RESET);
        }

        printf("\n");

    } while (escolha != 3);

    free(lista);
    return 0;
}