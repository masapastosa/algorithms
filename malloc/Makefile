CC=gcc
all:
	$(CC) malloc.c test.c -o prog -Wall -Wextra
debug:
	$(CC) malloc.c test.c -o prog -Wall -Wextra -ggdb
run: debug
	gdb ./prog
clean:
	rm prog
