CC = g++
LFLAGS = -o
CFLAGS = -c -g -Wall -Werror
INC = ./inc
IFLAG = -I$(INC)
BIN = ./bin
OBJ = ./obj
SRC = ./src

all: Sysprg

Sysprg: $(OBJ)/Sysprg.o
	$(CC) $(LFLAGS) Sysprg $(OBJ)/Sysprg.o
	mv Sysprg.o $(OBJ)
$(OBJ)/Sysprg.o: $(SRC)/Sysprg.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/Sysprg.cpp 
	mv *.o $(OBJ)


clean:
	@echo "Cleaning is in Progress"
	rm -f a.out Sysprg
	rm -f *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/Sysprg
	@echo "Done!"


