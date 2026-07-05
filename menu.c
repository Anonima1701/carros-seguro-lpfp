#include <stdio.h>
#include <stlib.h>
#include "menu.h"

#include "veiculo.h"
#include "condutor.h"
#include "cotacao.h"
#include "arquivo.h"
#include "relatorio.h"

Void menuCadastro(){
    linha()
    printf("1. Cadastrar veiculo\n");
    printf("2. Exibir veiculos cadastrados\n");
    printf("3. Cadastrar condutor\n");
    printf("4. Exibir condutores cadastrados\n"):
    printf("5. Calcular cotações \n");
    printf("6. Voltar\n");
    linha();

    if (scanf("%d", &op) != 1) {
            printf("Digite apenas numeros!\n");
            while (getchar() != '\n');
            op = -1;
            continue;
        }
        while (getchar() != '\n');

        switch(op) {
            case 1:
            void cadastrarVeiculo(Veiculo *v);
                break;
            case 2:
            void exibirVeiculo(Veiculo *v);
                break;
            case 3:
            void cadastrar_condutor(Condutor *c);
                break;
            case 4:
            void exibir_condutor(Condutor *c);
                break;
            case 5:
                if (!temVeiculo || !temCondutor) {
                    printf("Cadastre primeiro o veiculo e o condutor.\n");
                    break;
                }

                nova.veiculo = v;
                nova.condutor = c;
                calcularCotacao(&nova);

                if (adicionarCotacao(&lista, &total, nova) && SalvarArquivo(&nova)) {
                    printf("Cotacao salva com sucesso!\n");
                    printf("Premio anual: R$ %.2f\n", nova.premio_anual);
                    printf("Premio mensal: R$ %.2f\n", nova.premio_mensal);
                }

                break;
            case 6:
            system("clear");
            printf("\nVoltando ao menu principal");
                break;

            default:
                printf("Opcao invalida\n");
        }
    while (op != 0);
}

void menuRelatorio(){
    printf("\n===== RELATORIOS =====\n");
        printf("1. Listar todas as cotacoes\n");
        printf("2. Filtrar por nome do condutor\n");
        printf("3. Exibir menor cotacao\n");
        printf("0. Voltar\n");
        printf("Escolha: ");

        if (scanf("%d", &op) != 1) {
            printf("Digite apenas numeros!\n");
            while (getchar() != '\n');
            op = -1;
            continue;
        }
        while (getchar() != '\n');

        switch (op) {
            case 1:
                Listar_cotacoes(lista, total);
                break;
            case 2:
                printf("Nome do condutor: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                filtrar_por_condutor(lista, total, nome);
                break;
            case 3:
                menor_cotacao(lista, total);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 0);












}










