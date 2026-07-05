//Relatorio(veiculo/cadastramento),Lista,filtra e compara as cotacoes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "linha.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
        printf(ANSI_COLOR_RED"\n-> Nenhuma cotacao encontrada\n"ANSI_COLOR_RESET);
        return;
    }
    

    printf(ANSI_COLOR_YELLOW"\n====== Lista de Cotacoes ======\n"ANSI_COLOR_RESET);

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

    printf(ANSI_COLOR_YELLOW"\n===== Busca por Condutor =====\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"Buscando por: %s\n\n" ANSI_COLOR_RESET ,nome);

    for (i = 0; i < total; i++) {

        int j = 0;
        int igual = 1;

        while (nome[j] != '\0' || lista[i].condutor.nome[j] != '\0') {

            if (nome[j] != lista[i].condutor.nome[j]) {
                igual = 0;
                break;
            }

            j++;
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
        printf(ANSI_COLOR_RED "-> Nenhum resultado encontrado para \"%s\".\n" ANSI_COLOR_RESET, nome);
    }
    linha();
}

void menor_cotacao(Cotacao *lista, int total) {
    int i;
    int indice = 0;

    if (total == 0) {
        system("clear");

        printf(ANSI_COLOR_RED"-> Nenhuma cotacao foi registrada\n" ANSI_COLOR_RESET);
        return;
    }

    for (i = 0; i < total; i++) {
        if (lista[i].premio_anual < lista[indice].premio_anual) {
            indice = i;
        }
    }

    Cotacao *c = &lista[indice];

    system("clear");
    linha();
    printf(ANSI_COLOR_YELLOW"\n======= MENOR COTACAO ========\n"ANSI_COLOR_RESET);
    printf("Condutor : %s\n", c->condutor.nome);
    printf("Veiculo : %s %s (%d)\n", c->veiculo.marca, c->veiculo.modelo, c->veiculo.ano);
    printf("Premio: R$ %.2f/ano\n | R$ %.2f/mes\n", c->premio_anual, c->premio_mensal);
    printf("Data : %s\n", c->data);
    linha();
}



