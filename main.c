#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "veiculo.h"
#include "arquivo.h"
#include "relatorio.h"
#include "condutor.h"
#include "cotacao.h"

//função linha
void linha () {
  printf("======================================\n");
}

//funcao pausar
void pausar() {
    printf("\nPressione ENTER para continuar...");
}


//Função principal
int main() {
  setlocale(LC_ALL, "Portuguese_Brazil"); //para ser aceito caracteres especiais.


  //Variaveis
  Veiculo v;
  int escolha;
  Condutor c;
  Cotacao *lista = NULL;
  int total = 0;

  //carregar cotações
  Listar_cotacoes(lista, total);
  total = CarregarArquivo(&lista);

  system("Clear");

  do {
        // Estrutura do Menu

        linha();
        printf("       Menu Principal         \n");
        linha();  
        printf("1. Cadastro (Veiculo,condutor e calculo de premio)\n");
        linha();
        printf("2. Relatorios\n");
        linha();
        printf("3. Exit\n");
        linha();
        printf("Escreva sua escolha: ");

        // Verificação de escolha
        if (scanf("%d", &escolha) != 1) {
            printf("Digite apenas numeros!\n");
        } else if (escolha < 1 || escolha > 3) {
            printf("Opcao invalida!\n");
        } else {
            printf("Opcao escolhida: %d\n", escolha);
        }
    
        // Opções a serem usadas
        switch (escolha) {
            case 1:
                system("clear");
                printf("\n-> Abrindo aba de cadastro\n");
                void menuCadastro();
            break;

            case 2 :
                system("clear");
                printf("\n-> Abrindo Relatórios\n");
                void menuRelatorio();
            break;

            case 3:
                system("clear");
                printf("\n Finalizando tarefa!\n");
            break;

            default:
                printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
        }
        
        printf("\n");

    } while (escolha != 3);
free(lista);
return 0;
}