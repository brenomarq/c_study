all: main.c main.o
	gcc main.c -o main
	./main

compile: main.c main.o
	gcc main.c -o main

run: main
	./main
