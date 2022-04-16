# Makefile
# Řešení IJC-DU2, 16.04.2022
# Autor: Filip Haužvic, FIT

CFLAGS=-std=c11 -pedantic -Wall -Wextra

HTAB_C=htab_bucket_count.c htab_clear.c htab_erase.c htab_find.c htab_for_each.c htab_free.c htab_hash_function.c htab_init.c htab_lookup_add.c htab_resize.c htab_size.c
HTAB_O=htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o

all : tail wordcount wordcount-dynamic

tail : tail.c
	gcc $(CFLAGS) tail.c -o tail

wordcount : io.o libhtab.a wordcount.c
	gcc $(CFLAGS) -o wordcount io.o wordcount.c -static -L. -lhtab

wordcount-dynamic : io.o libhtab.so 
	gcc $(CFLAGS) -o wordcount-dynamic io.o wordcount.c -L. -lhtab

#########################################################
io.o : io.c io.h
	gcc $(CFLAGS) -c io.c

libhtab.a: $(HTAB_C) htab.h htab_private.h
	gcc $(CFLAGS) -c $(HTAB_C)
	ar -cr libhtab.a $(HTAB_O)
	ranlib libhtab.a

libhtab.so: $(HTAB_C) htab.h htab_private.h
	gcc $(CFLAGS) -c -fPIC $(HTAB_C)
	gcc $(CFLAGS) -shared -fPIC $(HTAB_O) -o libhtab.so

clean :
	rm -f tail wordcount wordount-dynamic *.o libhtab.a libhtab.so