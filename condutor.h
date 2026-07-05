#ifndef CONDUTOR_H
#define CONDUTOR_H

typedef struct {
    char nome[80];
    char rg[5];
    int idade;
    int sinistros;
    char cnh;
} Condutor;

void cadastrar_condutor(Condutor *c);
void exibir_condutor(Condutor *c);
void pausar();

#endif
