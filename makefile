CC = g++
OBJS = src/*.cpp
OBJ_NAME = pong
LINKER_FLAGS = -lSDL2 -lSDL2_image
COMPILER_FLAGS = -std=c++11
BIN = bin/

#Compile and run
all :
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BIN)$(OBJ_NAME)
	$(BIN)$(OBJ_NAME)
