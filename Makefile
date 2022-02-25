SRC := ./src
OBJ := ./obj
CC := g++
CFLAGS := --std=c++17
all: markov.out
	@echo Success
markov.out: $(OBJ)/table.o $(OBJ)/graph.o $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(OBJ)/table.o $(OBJ)/graph.o $(SRC)/main.cpp -o markov.out

$(OBJ)/table.o: $(SRC)/table.cpp $(SRC)/data.h
	$(CC) $(CFLAGS) -c $(SRC)/table.cpp -o $(OBJ)/table.o

$(OBJ)/graph.o: $(SRC)/graph.cpp $(SRC)/data.h
	$(CC) $(CFLAGS) -c $(SRC)/graph.cpp -o $(OBJ)/graph.o

clean:
	rm $(OBJ)/*.o ./markov.out