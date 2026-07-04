#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "veiculo.h"
#include "salvar.h"
#include "Relatorio.h"
#include "condutor.h"
#include "cotacao.h"

//função linha
void linha () {
  printf("======================================\n");
}
//painel
void pausar() {
  printf("\nPressione Enter para continuar...\n");
  while (getchar() != '\n');
  getchar();
}

//Função principal
int main() {
  setlocale(LC_ALL, "Portuguese"); //para ser aceito caracteres especiais.
  
  //Variaveis
  Veiculo v;
  int escolha;
  Condutor c;

  do {
      //Atualizar valor
      int valor1;

      // Estrutura do Menu
      system("clear");
      linha();
      printf("       Menu Principal         \n");
      linha();  
      printf("1. Cadastrar Veículo\n");
      linha();
      printf("2. Exibir Veiculo\n");
      linha();
      printf("3. Cadastrar Condutor\n");
      linha();
      printf("4. Exibir Condutor\n");
      linha();
      printf("5. Exit\n");
      linha();
      printf("Escreva sua escolha: ");
  
      // Verificação de escolha
      if (scanf("%d", &escolha) != 1) {
          printf("\n[Erro] Opção invalida. Por favor, escolha um número entre 1 e 5.\n");
          continue; 
      }
  
      // Opções a serem usadas
      switch (escolha) {

          case 1:
              printf("\n-> Iniciando Cadastro do Veículo\n");
              cadastrarVeiculo(&v);
              break;

          case 2 :
              printf("\n-> Exibindo informações do veículo\n");
              exibirVeiculo(&v);
              break;

          case 3:
              system("clear");
              printf("\nFinalizando tarefa!\n");
              CriarArquivo (&v);
              break;
          default:
              printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
      }
      printf("\n");

  } while (escolha != 3);

return 0;
}