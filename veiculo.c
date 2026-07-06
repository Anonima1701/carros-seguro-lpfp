//LAUANNA VICTORIA - MATRICULA: 20242SI0004
#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "linha.h"

// Cores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void cadastrarVeiculo(Veiculo *v) {

    printf(ANSI_COLOR_YELLOW "\n------ Cadastro de Veículo ------\n" ANSI_COLOR_RESET);

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

    system("clear");

    printf(ANSI_COLOR_GREEN "\n-> Veículo cadastrado com sucesso!\n" ANSI_COLOR_RESET);

}
//Função para exibir veículo
void exibirVeiculo(Veiculo *v) {
    system("clear");

    if (v == NULL) {
        printf(ANSI_COLOR_RED "-> Veículo inexistente!\n" ANSI_COLOR_RESET);
        return;
    }

    printf(ANSI_COLOR_YELLOW "\n------ Informações do Veículo -------\n" ANSI_COLOR_RESET);
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