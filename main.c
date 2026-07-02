#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "veiculo.h"
#include "salvar.h"

void linha () {
  printf("======================================\n");
}

//Função principal
int main() {
  setlocale(LC_ALL, "Portuguese"); //para ser aceito caracteres especiais.
  
  //Variaveis
  Veiculo v;
  int escolha;
  VerificarExistencia();
  
  do {
      //Atualizar valor
      int valor1;
      
      // Estrutura do Menu
      system("clear");
      linha();
      printf("       Menu Principal         \n");
      linha();
      exibirVeiculo(&v);
      printf("\n");
      linha();
      printf("1. Cadastrar Veículo\n");

      //printf("2. Exibir Veículo\n");

      printf("2. Exit\n");
      linha();
      printf("Escreva sua escolha: ");
  
      // Verificação de escolha
      if (scanf("%d", &escolha) != 1) {
          printf("\n[Erro] Opção invalida. Por favor, escolha um número.\n");
          stdin = freopen(NULL,"r",stdin);
          continue; 
      }
  
      // Opções a serem usadas
      switch (escolha) {
          
          case 1:
              printf("\n-> Iniciando Cadastro do Veículo\n");
              cadastrarVeiculo(&v);
              break;

          /*
          case 2 :
              printf("\n-> Exibindo informações do veículo\n");
              exibirVeiculo(&v);
              break;
          */

          case 2:
              system("clear");
              printf("\nFinalizando tarefa!\n");
              CriarArquivo (&v);
              break;
          default:
              printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
      }
      printf("\n");

  } while (escolha != 2);

return 0;

}
