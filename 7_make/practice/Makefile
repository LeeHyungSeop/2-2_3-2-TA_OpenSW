BIN_DIR = ./bin
INC_DIR = ./include
OBJ_DIR = ./obj
LIB_DIR = ./lib
SRC_DIR = ./src
GCC_OPT = -I$(INC_DIR) -g -Wall
OBJS = $(OBJ_DIR)/func1.o $(OBJ_DIR)/func2.o

all : $(BIN_DIR)/myapp

$(BIN_DIR)/myapp : $(SRC_DIR)/main.c $(LIB_DIR)/libshared.so.1.0
	gcc $(SRC_DIR)/main.c -L$(LIB_DIR) -lshared -o $(BIN_DIR)/myapp $(GCC_OPT)
	export LD_LIBRARY_PATH=$(PWD)$(LIB_DIR)
	$@

$(LIB_DIR)/libshared.so.1.0 : $(OBJS)
	gcc -fPIC -shared -Wl,-soname=libshared.so.1 $(OBJS) -o $(LIB_DIR)/libshared.so.1.0 -lc;\
	ln -s libshared.so.1.0 $(LIB_DIR)/libshared.so; \
	ln -s libshared.so.1.0 $(LIB_DIR)/libshared.so.1;

$(OBJ_DIR)/func1.o : $(SRC_DIR)/func1.c
	gcc -c -fPIC $< -o $@ $(GCC_OPT)
$(OBJ_DIR)/func2.o : $(SRC_DIR)/func2.c
	gcc -c -fPIC $< -o $@ $(GCC_OPT)

clean : 
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/myapp
	rm -rf $(LIB_DIR)/*.a $(LIB_DIR)/*.so*