#ifndef cotacao_h
#define cotacao_h

//outras bibliotecas
#include "veiculo.h"
#include "condutor.h"

typedef struct {
    Veiculo veiculo;
    Condutor condutor;
    float premio_anual;
    float premio_mensal;
    char data[11];
} Cotacao;

//protótipos das funções
float calctaxaSeguro(Veiculo *v, Condutor *c);
float calcpremioSeguro(Veiculo *v, Condutor *c);
float calcpremioMensal(float premioAnual);
void calcCotacao(Cotacao *cotacao);


#endif