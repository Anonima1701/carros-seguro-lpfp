CC = gcc
C_FLAGS = -Wall -Wextra

all: cotacao

cotacao: main.o veiculo.o salvar.o condutor.o
	$(CC) $(CFLAGS) main.o veiculo.o salvar.o condutor.o -o cotacao
main.o: main.c veiculo.h salvar.h condutor.h
	$(CC) -c main.c -o main.o
veiculo.o: veiculo.c veiculo.h
	$(CC) -c veiculo.c -o veiculo.o
salvar.o: salvar.c salvar.h
	$(CC) -c salvar.c -o salvar.o
condutor.o: condutor.c condutor.h
	$(CC) -c condutor.c -o condutor.o
clean:
	rm *.o cotacao
.PHONY:clean