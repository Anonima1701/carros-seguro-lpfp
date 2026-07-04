CC = gcc
C_FLAGS = -Wall -Wextra

all: cotacao

cotacao: main.o veiculo.o arquivo.o condutor.o relatorio.o
	$(CC) $(CFLAGS) main.o veiculo.o arquivo.o condutor.o relatorio.o -o cotacao

main.o: main.c veiculo.h arquivo.h condutor.h
	$(CC) -c main.c -o main.o

veiculo.o: veiculo.c veiculo.h
	$(CC) -c veiculo.c -o veiculo.o

arquivo.o: arquivo.c arquivo.h
	$(CC) -c arquivo.c -o arquivo.o

condutor.o: condutor.c condutor.h
	$(CC) -c condutor.c -o condutor.o

relatorio.o: relatorio.c relatorio.h
	$(CC) -c relatorio.c -o relatorio.o
	
clean:
	rm *.o cotacao
.PHONY:clean