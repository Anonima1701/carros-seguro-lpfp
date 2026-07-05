//LAUANNA VICTORIA - MATRICULA: 20242SI0004
#ifndef VEICULO_H
#define VEICULO_H
// Estrutura para armazenar informações do veículo
    typedef struct veiculo {
        char marca[50];
        char modelo[50];
        int ano;
        float valor_mercado;
        char tipo;
    } Veiculo;

void cadastrarVeiculo(Veiculo *v);
void exibirVeiculo(Veiculo *v);

#endif