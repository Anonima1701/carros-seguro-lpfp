CC = gcc
C_FLAGS = -Wall -Wextra

all: cotacao

cotacao: main.o veiculo.o arquivo.o condutor.o relatorio.o cotacao.o
	$(CC) $(C_FLAGS) main.o veiculo.o arquivo.o condutor.o relatorio.o cotacao.o -o cotacao

main.o: main.c veiculo.h arquivo.h condutor.h cotacao.h relatorio.h
	$(CC) -c main.c -o main.o

veiculo.o: veiculo.c veiculo.h
	$(CC) -c veiculo.c -o veiculo.o

arquivo.o: arquivo.c arquivo.h cotacao.h
	$(CC) -c arquivo.c -o arquivo.o

condutor.o: condutor.c condutor.h
	$(CC) -c condutor.c -o condutor.o

relatorio.o: relatorio.c relatorio.h cotacao.h
	$(CC) -c relatorio.c -o relatorio.o

cotacao.o: cotacao.c cotacao.h veiculo.h condutor.h
	$(CC) -c cotacao.c -o cotacao.o

clean:
	rm -f *.o cotacao

.PHONY: clean