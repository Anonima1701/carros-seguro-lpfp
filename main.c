#include <stdio.h>

void linha () {
  printf("=≈==================");
}

//Função principal
int main() {
  //Variaveis
  linha();
  int escolha;
  
  do {
      //Atualizar valor
      int valor1;
      
      // Estrutura do Menu
      printf("%s", linha);
      printf("       Menu Principal         \n");
      printf("%d", valor1);
      printf(linha);
      printf("1. Receber valor\n");
      printf("2. Exit\n");
      printf(linha);
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
              printf("\n-> Valor: \n");
              scanf("%d", &valor1);
              break;
          case 2:
              printf("\nFinalizando tarefa!\n");
              break;
          default:
              printf("\n[Aviso] Opção incorreta! Tente novamente.\n");
      }
  } while (escolha != 2);

return 0;
}
