#include "cotacao.h"

float calcularTaxa(Veiculo *v, Condutor *c)
{
    float taxa = 0.04;

    // Se veículo com até 3 anos
    if (2026 - v->ano <= 3)
        taxa += 0.015;

    // Idade do condutor
    if (c->idade < 25)
        taxa += 0.02;
    else if (c->idade >= 65)
        taxa += 0.01;

    // Sinistros
    int sinistros = c->sinistros;
    if (sinistros > 3)
        sinistros = 3;

    taxa += sinistros * 0.015;

    // Desconto CNH C
    if (c->cnh == 'C')
        taxa -= 0.005;

    return taxa;
}

float calcularPremioAnual(Veiculo *v, Condutor *c)
{
    float premio = v->valor_mercado * calcularTaxa(v, c);

    if (v->tipo == 'E')
        premio *= 1.4;

    return premio;
}

float calcularPremioMensal(float premioAnual)
{
    return premioAnual / 12.0;
}

void calcularCotacao(Cotacao *c)
{
    c->premio_anual = calcularPremioAnual(&c->veiculo, &c->condutor);
    c->premio_mensal = calcularPremioMensal(c->premio_anual);
}