APPS = ./apps
BIN = ./bin
INCLUDES = ./includes
OBJ = ./obj
SRC = ./src


all: 
	gcc -o3 -c $(SRC)/bisseccao.c -I $(INCLUDES) -o $(OBJ)/bisseccao.o
	gcc -o3 -c $(SRC)/funcao.c -I $(INCLUDES) -o $(OBJ)/funcao.o
	gcc -o3 $(APPS)/Programa.c $(OBJ)/*.o -I $(INCLUDES) -o $(BIN)/programa


run:
	./$(BIN)/programa



clean: 
	rm $(BIN)/* $(OBJ)/* 
