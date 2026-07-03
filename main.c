#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "veiculo.h"
#include "salvar.h"
#include "condutor.h"

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

          case 2 :
              printf("\n-> Exibindo informações do veículo\n");
              exibirVeiculo(&v);
              break;

          //case 3:
             // system("clear");
              //printf("\n-> Iniciando Cadastro do Condutor!\n");
              //cadastrar_condutor(&c);
              //break;

          //case 4:
              //system("clear");
              //printf("\n-> Exibindo Informações do Condutor!\n");
              //exibir_condutor(&c);
              //break;//

          case 5:
              system("clear");
              printf("\nFinalizando tarefa!\n");
              CriarArquivo (&v);
              break;
          default:
              printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
      }
      printf("\n");

  } while (escolha != 5);

return 0;

}
