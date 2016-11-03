CC=gcc
BIN=./bin
LIB=./lib
SRC=./src

all: tests

clean:
	-rm $(BIN)/*
	-rm ./run_all_tests

tests:
	make testgen
	make testrun
	./run_all_tests

testgen:
	$(CC) -o $(BIN)/generate_includes $(SRC)/test_scan.c
	$(BIN)/generate_includes
	rm $(BIN)/generate_includes

testrun:
	$(CC) -o ./run_all_tests $(SRC)/driver.c -I$(SRC)

