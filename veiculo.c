//LAUANNA VICTORIA - MATRICULA: 20242SI0004
#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"

void cadastrarVeiculo(Veiculo *v) {
    printf("Digite a marca do veículo: ");
    scanf("%s", v->marca);
    while (getchar() != '\n');

    printf("Digite o modelo do veículo: ");
    scanf("%s", v->modelo);
    while (getchar() != '\n');

    printf("Digite o ano do veículo: ");
    scanf("%d", &v->ano);
    while (getchar() != '\n');

    printf("Digite o valor do veículo: R$ ");
    scanf("%f", &v->valor_mercado);
    while (getchar() != '\n');

    do {
        printf("Digite o tipo do veículo (P-Passeio, U-Utilitário, E-Esportivo): ");
        scanf(" %c", &v->tipo);
        while (getchar() != '\n');
    } while (v->tipo != 'P' && v->tipo != 'U' && v->tipo != 'E');
}

void exibirVeiculo(Veiculo *v) {
    system("clear");

    printf("\n------ Informações do Veículo ------\n");
    printf("Marca: %s\n", v->marca);
    printf("Modelo: %s\n", v->modelo);
    printf("Ano: %d\n", v->ano);
    printf("Valor: R$ %.2f\n", v->valor_mercado);
    
    printf("Tipo: ");
    switch (v->tipo) {
        case 'P':
            printf("Passeio\n");
            break;
        case 'U':
            printf("Utilitário\n");
            break;
        case 'E':
            printf("Esportivo\n");
            break;
        default:
            printf("Tipo desconhecido\n");
            break;
    }
}