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
    printf("Digite apenas numeros!\n");
}
      else if (escolha < 1 || escolha > 5) {
    printf("Opcao invalida!\n");
}
      else {
    printf("Opcao escolhida: %d\n", escolha);
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

<<<<<<< HEAD
} 

 
//Relatóio de Cotações

//"Esqueleto" do Sistema:

typedef struct {
   char Marca[50];
   char Modelo[50];
   int ano;
   float valor_de_mercado;
   char tipo;
}Veiculo;

typedef struct {
   char nome[50];
   char RG[11];
   int idade;
   int sinistros;
   char CNH;
}Condutor;

typedef struct{
   Veiculo veiculo;
   Condutor condutor;
   float premio_anual;
   float premio_menal;
   char data[11];
}Cotacao;

//funções para o relatorio de cotações:

void Listar_cotacoes(Cotacao *lista, int total);
void filtrar_condutor(Cotacao *lista, int total, char *nome);
void menor_cotacao(Cotacao *lista, int total);

#endif
 
//Relatório(veiculo/cadastramento)Lista,filtra e compara as cotações:


//Mostra o tipo de veículo

static char *tipo_de_veiculo(char tipo) {
      if (tipo == 'P') 
      return "PASSEIO";
      
      if (tipo == 'U')
      return "UTILITARIO";

      if(tipo == 'E')
      return "ESPORTIVO";
}
 //Lista as cotações que foram salvas
void Listar_cotacoes(Cotacao *lista, int total) {
     int i;

     if (total == 0) {
        printf("Nenhuma cotacao foi encontrada\n");
        return;
}
}
 
 printf("\n====== LISTA DE COTACOES ======\n");

 for (i = 0;i < total; i++0) {
      Cotacao *c = &lista[i];

      printf("\n[%d] Data: %s\n", i + 1, c-> data);
      printf("Condutor : %s\n", c-> condutor.Nome);
      printf("Veiculo : %s %s (%d)\n", c-> veiculo.Marca, c-> veiculo.Modelo, c-> veiculo.ano);
      printf("Tipo : %s\n", tipo_de_veiculo(c-> veiculo.tipo));
      printf("Valor : R$ %2.f\n", c-> veiculo.valor_de_mercado);
      printf("Premio : R$ %2.f/ano | R$ %2.f/mes\n, c-> premio_anual, c-> premio_mensal);
}
 linha();

}
//Filtra as cotacoes do condutor

void filtrar_por_condutor(Cotacao *lista, int total, char *nome) {
     int i;
     int achou = 0;
     Cotacao *c;

     printf("\n====== Buscar por Condutor ======\n");
     printf("Buscando por: %\n\n", nome);
     
     for(i = 0;i < total; i++);
     //strstr verifica se o nome que foi digitado aparece em algum lugar
     if (strstr(lista[i].condutor.Nome, nome) !=NULL) {
        c = &lista[i];
     
        printf("[%d] %s - %s %s\n" i + 1, c-> condutor.Nome, c->veiculo.Marca, c->veiculo.Modelo);
        printf("Premio Anual : R$ %.2f\n", c-> premio_anual);
        printf("Data:%s\n", c-data);

        achou = 1;
   }
}
if(!achou) {
   printf("Nenhum resultado encontrado para \"%s\".n", nome);
}
linha();
}

void menor_cotacao(Cotacao *lista, int total) {
     int i;
     int indice = 0;
  
     if(total == 0) {
       printf("Nenhuma cotacao registrada\n");
       return;
}
//Compara as cotacoes e assume o menor valor encontrado
for(i =0;i < total; i++) {
    if(lista[i].premio_anual < lista[indicie].premio_anual) {
       indice = i;
    }
}
 
  Cotacao *c &lista[indice];

printf("Condutor: %s\n", c->condutor.Nome);
printf("Veiculo: %s\n", c->veiculo.Marca, c->veiculo.Modelo, c->veiculo.ano);
printf("Premio: R$ %.2f/ano\n | R$ %.2f/mes\n", c->premio_anual, c->premio_mensal);
printf("Data: %s\n", c->data);  
=======
}
>>>>>>> 3300622f27a92c8337b9e9dfe68c7719aa055acd
