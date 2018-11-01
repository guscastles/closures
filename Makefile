SRC=src
OBJ=obj
BIN=bin
OBJ_FILES=main.o operation.o
HDR=h
ODIR=$(patsubst %,$(OBJ)/%, $(OBJ_FILES))

all: $(ODIR)

clean:
	rm obj/* bin/*

$(OBJ)/%.o: $(SRC)/%.c
	gcc -c -o $@ $< -I $(HDR)/

main: $(ODIR)
	gcc -o $(BIN)/$@ $^ -I $(HDR)/  

install: main
	cp $(BIN)/$< ~/bin

run: install
	main
