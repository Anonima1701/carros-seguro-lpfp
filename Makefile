CC = gcc
C_FLAGS = -Wall -Wextra

all: cotacao

cotacao: main.o veiculo.o salvar.o
	$(CC) $(CFLAGS) main.o veiculo.o salvar.o -o cotacao
main.o: main.c veiculo.h salvar.h
	$(CC) -c main.c -o main.o
veiculo.o: veiculo.c veiculo.h
	$(CC) -c veiculo.c -o veiculo.o
salvar.o: salvar.c salvar.h
	$(CC) -c salvar.c -o salvar.o
clean:
	rm *.o cotacao
.PHONY:clean