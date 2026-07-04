#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "arquivo.h"

// Definição do nome
const char *filename = "log";

void VerificarExistencia() {
    struct stat buffer;

    // Define horario local
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Codigo de verificação e criação
    if (stat(filename, &buffer) != 0) {
        printf("Arquivo não existe. Criando %s...\n", filename);
        
        // Abre Arquivo e verifica existencia
        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            perror("Erro ao criar o arquivo");
            return;
        }

        //Cabeçalho do log
        fprintf(file, "--- Início do Log ---\n");
        fprintf(file, "%s", asctime(tm));

        // Fecha Arquivo
        fclose(file);

    } else {
        printf("O arquivo já existe. Pronto para uso.\n");
    }
}

void CriarArquivo(Veiculo *v) {
    // Abre o arquivo
    FILE *file = fopen(filename, "a");

    // Verifica Existencia
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para arquivo o veículo");
        return;
    }

    // Converte o char do tipo para texto legível de forma isolada
    const char* tipo_txt;
    switch (v->tipo) {
        case 'P': tipo_txt = "Passeio"; break;
        case 'U': tipo_txt = "Utilitário"; break;
        case 'E': tipo_txt = "Esportivo"; break;
        default:  tipo_txt = "Nenhum cadastrado"; break;
    }

    // Escreve diretamente no arquivo de forma organizada
    fprintf(file, "------ Veículo Salvo ------\n");
    fprintf(file, "Marca: %s\n", v->marca);
    fprintf(file, "Modelo: %s\n", v->modelo);
    fprintf(file, "Ano: %d\n", v->ano);
    fprintf(file, "Valor: R$ %.2f\n", v->valor_mercado);
    fprintf(file, "Tipo: %s\n", tipo_txt);
    fprintf(file, "---------------------------\n\n");

    // Fecha o Arquivo
    fclose(file);
}