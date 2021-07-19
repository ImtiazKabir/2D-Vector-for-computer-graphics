all:
	gcc -Wall -Wextra -Wconversion -Wpedantic main.c vector.c -o main -lm
