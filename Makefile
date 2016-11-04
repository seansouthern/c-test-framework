CC=gcc
BIN=./bin
LIB=./lib
SRC=./src

all: tests

clean:
	-rm $(BIN)/*
	-rm ./run_all_tests

tests: testgen testrun
	./run_all_tests

testgen:
	$(CC) -o $(BIN)/generate_includes $(SRC)/scan_driver.c
	$(BIN)/generate_includes
	rm $(BIN)/generate_includes

testrun:
	$(CC) -o ./run_all_tests $(SRC)/driver.c -I$(SRC)

