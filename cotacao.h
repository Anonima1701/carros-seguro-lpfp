#ifndef COTACAO_H
#define COTACAO_H

#include "veiculo.h"
#include "condutor.h"

typedef struct {
    Veiculo veiculo;
    Condutor condutor;
    float premio_anual;
    float premio_mensal;
    char data[11];
} Cotacao;

// protótipos das funções
float calcularTaxa(Veiculo *v, Condutor *c);
float calcularPremioAnual(Veiculo *v, Condutor *c);
float calcularPremioMensal(float premioAnual);
void calcCotacao(Cotacao *cotacao);

#endif