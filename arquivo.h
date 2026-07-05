#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "veiculo.h"

void VerificarExistencia ();
void CriarArquivo (Veiculo *v);
int CarregarArquivo (Cotacao **lista);
int SalvarArquivo(Cotacao *c);
int adicionarCotacao(Cotacao **lista, int *total, Cotacao nova);

#endif