//LAUANNA VICTORIA - MATRICULA: 20242SI0004
#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "linha.h"
//Função para cadastrar veículo
void cadastrarVeiculo(Veiculo *v) {
    system("clear");

    printf("\n------ Cadastro de Veículo ------\n");
    printf("Digite a marca do veículo: ");
    scanf("%s", v->marca);
    while (getchar() != '\n'); // Limpar o buffer de entrada

    printf("Digite o modelo do veículo: ");
    scanf("%s", v->modelo);
    while (getchar() != '\n');

    printf("Digite o ano do veículo: ");
    scanf("%d", &v->ano);
    while (getchar() != '\n');

    printf("Digite o valor do veículo: R$ ");
    scanf("%f", &v->valor_mercado);
    while (getchar() != '\n');
// Loop para garantir que o tipo do veículo seja válido
    do {
        printf("Digite o tipo do veículo (P-Passeio, U-Utilitário, E-Esportivo): ");
        scanf(" %c", &v->tipo);
// Converte o tipo para maiúsculo, se o usuário digitou em minúsculo.
        if (v->tipo == 'p') {
            v->tipo = 'P';
        } else if (v->tipo == 'u') {
            v->tipo = 'U';
        } else if (v->tipo == 'e') {
            v->tipo = 'E';
        }

    } while (v->tipo != 'P' && v->tipo != 'U' && v->tipo != 'E');

    printf("\nVeículo cadastrado com sucesso!\n");
    system("clear");
}
//Função para exibir veículo
void exibirVeiculo(Veiculo *v) {
    system("clear");
    
    if (v == NULL) {
        printf("Veículo inexistente!\n");
        return;
    }

    printf("\n------ Informações do Veículo -------\n");
    printf("Marca: %s\n", v->marca);
    printf("Modelo: %s\n", v->modelo);
    printf("Ano: %d\n", v->ano);
    printf("Valor: R$ %f\n", v->valor_mercado);

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
    pausar();
}