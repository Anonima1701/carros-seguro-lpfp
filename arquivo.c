#include <stdio.h>
#include <time.h> //biblioteca de tempo local
#include "arquivo.h"

// Definição do nome
const char *filename = "log";

void verificarExistencia() {

    FILE *file;

    // Define horário local
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    file = fopen(filename, "r");

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

    const char* tipo_txt;
    switch (v->tipo) {
        case 'P': tipo_txt = "Passeio"; break;
        case 'U': tipo_txt = "Utilitário"; break;
        case 'E': tipo_txt = "Esportivo"; break;
        default:  tipo_txt = "Nenhum cadastrado"; break;
    }

    fprintf(file, "------ Veículo Salvo ------\n");
    fprintf(file, "Marca: %s\n", v->marca);
    fprintf(file, "Modelo: %s\n", v->modelo);
    fprintf(file, "Ano: %d\n", v->ano);
    fprintf(file, "Valor: R$ %.2f\n", v->valor_mercado);
    fprintf(file, "Tipo: %s\n", tipo_txt);
    fprintf(file, "---------------------------\n\n");

    fclose(file);
}