//Relatorio 
#ifndef RELATORIO_H 
#define RELATORIO_H

//"esqueleto" do sitema

typedef struct {
    char Marca[50];
    char Modelo [50];
    int ano;
    float valor_de_mercado;
    char tipo;
}Veiculo;

typedef struct {
    char Nome [50];
    char RG [11];
    int idade;
    int sinistros;
    char CNH;
}Condutor;

typedef struct {
   Veiculo veiculo;
   Condutor condutor;
   float premio_anual;
   float premio_mensal;
   char data[11];
}Cotacao;

//Funcoes para o relatorio

void Listar_cotacoes(Cotacao *lista, int total);
void filtrar_por_condutor(Cotacao *lista, int total, char *nome);
void menor_cotacao(Cotacao *lista, int total);

#endif