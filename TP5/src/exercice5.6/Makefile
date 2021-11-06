CC ?= gcc

CFLAGS=-Wall -Wextra -g

COBJS ?= client2.o repertoire.o
SOBJS ?= serveur2.o calcul.o operator.o

.SUFFIXES: .c .o

SERVER = serveur2
CLIENT = client2

all: $(SERVER) $(CLIENT)

$(SERVER): $(SOBJS)
	$(CC) -o $(SERVER) $(SOBJS)

$(CLIENT): $(COBJS)
	$(CC) -o $(CLIENT) $(COBJS)

.c.o:
	$(CC) -c $*.c

