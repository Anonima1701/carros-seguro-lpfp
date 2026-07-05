#ifndef MENU_H
#define MENU_H

#include "veiculo.h"
#include "condutor.h"
#include "cotacao.h"

void menuCadastro(Veiculo *v, Condutor *c, Cotacao **lista, int *total);
void menuRelatorio(Cotacao *lista, int total);

#endif