//Relatorio(veiculo/cadastramento),Lista,filtra e compara as cotacoes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "linha.h"

//Mostra o tipo de veiculo

char *tipo_de_veiculo(char tipo) {
    if (tipo == 'P')
        return "PASSEIO";

    if (tipo == 'U')
        return "UTILITARIO";

    if (tipo == 'E')
        return "ESPORTIVO";

    return "DESCONHECIDO";
}
//Lista as cotacoes salvas
void Listar_cotacoes(Cotacao *lista, int total) {
    int i;
    system("clear");

    if (total == 0) {
        printf("\n-> Nenhuma cotacao encontrada\n");
        return;
    }
    

    printf("\n====== Lista de Cotacoes ======\n");

    for (i = 0; i < total; i++) {
        Cotacao *c = &lista[i];

        printf("\n[%d] Data: %s\n", i + 1, c -> data);
        printf(" Condutor : %s\n", c-> condutor.nome);
        printf(" Veiculo : %s %s (%d)\n ", c-> veiculo.marca, c-> veiculo.modelo, c-> veiculo.ano);
        printf(" Tipo : %s\n", tipo_de_veiculo(c-> veiculo.tipo));
        printf(" Valor : R$ %.2f\n", c-> veiculo.valor_mercado);
        printf(" Premio : R$ %.2f/ano | R$ %.2f/mes\n", c-> premio_anual, c-> premio_mensal);
    }
    linha();
}
//Filtra as cotacoes do condutor
void filtrar_por_condutor(Cotacao *lista, int total, char *nome) {
    int i;
    int achou = 0;
    Cotacao *c;

    system("clear");

    printf("\n===== Busca por Condutor =====\n");
    printf("Buscando por: %s\n\n", nome);

    for (i = 0; i < total; i++) {

        int j = 0;
        int igual = 1;

        while (nome[j] != '\0' && lista[i].condutor.nome[j] != '\0') {

            if (nome[j] != lista[i].condutor.nome[j]) {
                igual = 0;
                break;
            }

            j++;
        }

        if (nome[j] != '\0' || lista[i].condutor.nome[j] != '\0') {
            igual = 0;
        }

        if (igual == 1) {

            c = &lista[i];

            printf("[%d] %s - %s %s\n",
                   i + 1,
                   c->condutor.nome,
                   c->veiculo.marca,
                   c->veiculo.modelo);

            printf(" Premio anual : R$ %.2f\n", c->premio_anual);
            printf(" Data: %s\n", c->data);

            achou = 1;
        }
    }

    if (!achou) {
        printf("-> Nenhum resultado encontrado para \"%s\".\n", nome);
    }
    linha();
}

void menor_cotacao(Cotacao *lista, int total) {
    int i;
    int indice = 0;

    if (total == 0) {
        system("clear");

        printf("-> Nenhuma cotacao foi registrada\n");
        return;
    }

    for (i = 0; i < total; i++) {
        if (lista[i].premio_anual < lista[indice].premio_anual) {
            indice = i;
        }
    }

    Cotacao *c = &lista[indice];

    system("clear");

    printf("\n======= MENOR COTACAO ========\n");
    printf("Condutor : %s\n", c->condutor.nome);
    printf("Veiculo : %s %s (%d)\n", c->veiculo.marca, c->veiculo.modelo, c->veiculo.ano);
    printf("Premio: R$ %.2f/ano\n | R$ %.2f/mes\n", c->premio_anual, c->premio_mensal);
    printf("Data : %s\n", c->data);
    linha();
}



