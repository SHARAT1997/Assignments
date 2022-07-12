CC = g++
LFLAGS = -o
CFLAGS = -c -g -Wall -Werror
INC = ./inc
IFLAG = -I$(INC)
BIN = ./bin
OBJ = ./obj
SRC = ./src

all:  app 
app:	$(OBJ)/main.o $(OBJ)/Employee.o
	$(CC)  $(LFLAGS) $(BIN)/app $(OBJ)/main.o $(OBJ)/Employee.o 

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/main.cpp 
	mv main.o $(OBJ)

$(OBJ)/Employee.o: $(SRC)/Employee.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/Employee.cpp 
	mv Employee.o $(OBJ)


clean:
	@echo "Cleaning is in Progress"
	rm -f a.out app
	rm -f *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/app 
	@echo "Done!"


