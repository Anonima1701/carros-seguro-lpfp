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

//Função principal
int main() {
    setlocale(LC_ALL, ""); //para ser aceito caracteres especiais.

    //Variaveis
    Veiculo v;
    Condutor c;
    Cotacao *lista = NULL;
    int total = 0;
    int escolha;

    //carregar cotações
    Listar_cotacoes(lista, total);
    total = CarregarArquivo(&lista);

    do {
        // Estrutura do Menu
        system("clear");

        linha();
        printf("         Menu Principal        \n");
        linha();
        printf("1. Cadastro (Veículo,condutor e cálculo de prêmio)\n");
        linha();
        printf("2. Relatórios\n");
        linha();
        printf("3. Exit\n");
        linha();
        printf("Escreva sua escolha: ");

        // Verificação de escolha
        if (scanf("%d", &escolha) != 1) {
            printf("Digite apenas numeros!\n");
        } else if (escolha < 1 || escolha > 3) {
            printf("Opção inválida!\n");
        } else {
            printf("Opção escolhida: %d\n", escolha);
        }

        // Opções a serem usadas
        switch (escolha) {
        case 1:
            system("clear");
            printf("\n-> Abrindo Menu de Cadastro\n");
            menuCadastro(&v, &c, &lista, &total);
            break;

        case 2 :
            system("clear");
            printf("\n-> Abrindo Menu de Relatórios\n");
            menuRelatorio(lista, total);
            break;

        case 3:
            system("clear");
            printf("\n-> Finalizando tarefa!\n");
            break;

        default:
            system("clear");
            printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
        }

        printf("\n");

    } while (escolha != 3);
    free(lista);
    return 0;
}