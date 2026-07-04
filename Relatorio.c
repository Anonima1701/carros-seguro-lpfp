//Relatorio(veiculo/cadastramento),Lista,filtra e compara as cotacoes
#include <stdio.h>
#include <string.h>
#include "Relatorio.h"

//Mostra o tipo de veiculo 

char *tipo_de_veiculo(char tipo){
     if (tipo == 'P') 
     return "PASSEIO";

     if(tipo == 'U')
     return "UTILITARIO";

     if (tipo == 'E')
     return "ESPORTIVO";

     return "DESCONHECIDO";
}
 //Lista as cotacoes salvas             
void Listar_cotacoes(Cotacao *lista, int total) {
    int i;

    if (total == 0) {
        printf("Nemhuma cotacao encontrada\n");
        return;
    }   
    
    printf("\n====== Lista de Cotacoes ======\n");

    for (i = 0; i < total; i++) {
        Cotacao *c = &lista[i];

        printf("\n[%d] Data: %s\n", i + 1, c -> data);
        printf(" Condutor : %s\n", c-> condutor.Nome);
        printf(" Veiculo : %s %s (%d)\n ", c-> veiculo.Marca, c-> veiculo.Modelo, c-> veiculo.ano);
        printf(" Tipo : %s\n", tipo_de_veiculo(c-> veiculo.tipo));
        printf(" Valor : R$ %.2f\n", c-> veiculo.valor_de_mercado);
        printf(" Premio : R$ %.2f/ano | R$ %.2f/mes\n", c-> premio_anual, c-> premio_mensal);
    }
    printf("\n==================================\n");
}
//Filtra as cotacoes do condutor
void filtrar_por_condutor(Cotacao *lista, int total, char *nome){
    int i;
    int achou = 0;
    Cotacao *c;

    printf("\n===== Busca por Condutor =====\n");
    printf("Buscando por: %s\n\n", nome);

    for (i = 0; i < total; i++) {

    int j = 0;
    int igual = 1;

    while (nome[j] != '\0' || lista[i].condutor.Nome[j] != '\0') {

        if (nome[j] != lista[i].condutor.Nome[j]) {
            igual = 0;
            break;
        }

        j++;
    }

    if (igual == 1) {

        c = &lista[i];

        printf("[%d] %s - %s %s\n",
               i + 1,
               c->condutor.Nome,
               c->veiculo.Marca,
               c->veiculo.Modelo);

        printf(" Premio anual : R$ %.2f\n", c->premio_anual);
        printf(" Data: %s\n", c->data);

        achou = 1;
    }
}

 if(!achou) {
    printf("Nenhum resultado encontrado para \"%s\".\n", nome);
}
 printf("\n==================================\n");
}
 
void menor_cotacao(Cotacao *lista, int total) {
    int i;
    int indice = 0;

    if(total == 0) {
       printf("Nenhuma cotacao foi registrada\n");
       return;
}

for (i = 0; i < total; i++) {
    if(lista[i].premio_anual < lista[indice].premio_anual) {
      indice = i;
   }
} 
  
  Cotacao *c = &lista[indice];

  printf("\n======= MENOR COTACAO ========\n");
  printf("Condutor : %s\n", c->condutor.Nome);
  printf("Veiculo : %s %s (%d)\n", c->veiculo.Marca, c->veiculo.Modelo, c->veiculo.ano);
  printf("Premio: R$ %.2f/ano\n | R$ %.2f/mes\n", c->premio_anual, c->premio_mensal);
  printf("Data : %s\n", c->data);
  printf("==================================\n");
}
 
   

