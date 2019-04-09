main: main.o
	gcc main.c -lm -o  main.o

main.o: main.c
	gcc main.c -lm -o main.o   
