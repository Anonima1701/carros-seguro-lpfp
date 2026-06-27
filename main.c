#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "veiculo.h"

void linha () {
  printf("=≈==================");
}

//Função principal
int main() {
  setlocale(LC_ALL, "Portuguese"); //para ser aceito caracteres especiais.
  
  //Variaveis
  Veiculo v;
  int escolha;
  
  do {
      //Atualizar valor
      int valor1;
      
      // Estrutura do Menu
      linha();
      printf("       Menu Principal         \n");
      printf("%d", valor1);
      linha();
      printf("1. Cadastrar Veículo\n");
      printf("2. Exibir Veículo\n");
      printf("3. Receber valor\n");
      printf("4. Exit\n");
      linha();
      printf("Escreva sua escolha: ");
  
      // Verificação de escolha
      if (scanf("%d", &escolha) != 1) {
          printf("\n[Erro] Opção invalida. Por favor, escolha um número.\n");
          clearInputBuffer();
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
              printf("\n-> Valor: \n");
              scanf("%d", &valor1);
              break;
          case 4:
              printf("\nFinalizando tarefa!\n");
              break;
          default:
              printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
      }

      printf("\n");

  } while (escolha != 4);

return 0;

}