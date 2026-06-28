CC = gcc
C_FLAGS = -Wall -Wextra

all: cotacao

cotacao: main.o veiculo.o
	$(CC) $(CFLAGS) main.o veiculo.o -o cotacao
main.o: main.c veiculo.h
	$(CC) -c main.c -o main.o
veiculo.o: veiculo.c veiculo.h
	$(CC) -c veiculo.c -o veiculo.o
clean:
	rm *.o cotacao
.PHONY:clean