CC = gcc

CFLAGS = -Wall -g

TARGET = bank

OBJ = main.o account.o transaction.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c account.h transaction.h
	$(CC) $(CFLAGS) -c main.c

account.o: account.c account.h
	$(CC) $(CFLAGS) -c account.c

transaction.o: transaction.c transaction.h
	$(CC) $(CFLAGS) -c transaction.c

clean:
	rm -f $(OBJ)
