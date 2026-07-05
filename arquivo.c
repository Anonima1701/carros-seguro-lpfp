#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //biblioteca de tempo local
#include "arquivo.h"

// Definição do nome
const char *filename = "log";

void verificarExistencia() {

    FILE *file = fopen(filename, "ab");

    // Define horário local
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);


    if (file == NULL) {

        printf("Arquivo nao existe. Criando %s...\n", filename);

        file = fopen(filename, "w");

        if (file == NULL) {
            printf("Erro ao criar o arquivo.\n");
            return;
        }

        // Cabeçalho do arquivo
        fprintf(file, "--- Inicio do Log ---\n");
        fprintf(file, "%s", asctime(tm));

        fclose(file);

    } else {

        printf("O arquivo ja existe. Pronto para uso.\n");

        fclose(file);
    }
}

void CriarArquivo(Veiculo *v) {
    // Abre o arquivo
    FILE *file = fopen(filename, "a");

    // Verifica Existencia
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para salvar o veículo");
        return;
    }

    const char *log;
    switch (v->tipo) {
        case 'P': log = "Passeio"; break;
        case 'U': log = "Utilitário"; break;
        case 'E': log = "Esportivo"; break;
        default:  log = "Nenhum cadastrado"; break;
    }

    fprintf(file, "------ Veículo Salvo ------\n");
    fprintf(file, "Marca: %s\n", v->marca);
    fprintf(file, "Modelo: %s\n", v->modelo);
    fprintf(file, "Ano: %d\n", v->ano);
    fprintf(file, "Valor: R$ %.2f\n", v->valor_mercado);
    fprintf(file, "Tipo: %s\n", log);
    fprintf(file, "---------------------------\n\n");

    fclose(file);
}
int adicionarCotacao(Cotacao **lista, int *total, Cotacao nova) {
    Cotacao *temp = realloc (*lista, (*total + 1) * sizeof(Cotacao));

    if (temp == NULL){
        printf("Erro: nao foi possivel realocar memoria.\n");
    return 0;
}
*lista = temp;
(*lista)[*total] = nova;
(*total)++;

return 1;
}

int CarregarArquivo(Cotacao **lista) {

    FILE *arquivo;
    Cotacao temp;
    int total = 0;


    arquivo = fopen("log", "rb");

    if (arquivo == NULL) {
        return 0;
    }

    while (fread(&temp, sizeof(Cotacao), 1, arquivo) == 1) {
        if(!adicionarCotacao(lista, &total, temp)){
        }
    }

    fclose(arquivo);
    return total;
}

int SalvarArquivo(Cotacao *c) {

    FILE *arquivo;

    arquivo = fopen("log", "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 0;
    }

   if (fwrite(c, sizeof(Cotacao), 1, arquivo) != 1){
    printf("Erro ao salvar cotação\n");
    fclose(arquivo);
   }

    fclose(arquivo);
    return 1;
}