//Relatorio 
#ifndef RELATORIO_H 
#define RELATORIO_H


//Funcoes para o relatorio

void Listar_cotacoes(Cotacao *lista, int total);
void filtrar_por_condutor(Cotacao *lista, int total, char *nome);
void menor_cotacao(Cotacao *lista, int total);

#endif