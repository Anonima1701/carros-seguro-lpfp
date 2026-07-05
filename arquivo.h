#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "cotacao.h"

int CarregarArquivo(Cotacao **lista);
int SalvarArquivo(Cotacao *c);
int adicionarCotacao(Cotacao **lista, int *total, Cotacao nova);

#endif