CFLAGS=-std=c11 -pedantic -Wall -Wextra

tail : tail.c
	gcc $(CFLAGS) tail.c -o tail

clean:
	rm -f tail *.o