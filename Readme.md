## C language project #1

Use ***make*** to compile, ***make clean*** to delete binaries.
make also creates static and dynamic libraries that implement a hash table

**Tail** prints out the last N lines (10 by default) from a file. If no file is given, read standard input.
Usage:  ./tail [-n LINE_COUNT] [file]

**Wordcount** reads the standard input and saves every word and the number of times that word has been used.
This is implemented using a hash table. This table is then printed.
**Wordcount-dynamic** uses dynamic libraries for hash table implementation, instead of static.
Needs to be launched with LD_LIBRARY_PATH="." and the libraries have to be in the same folder.
Usage:  ./wordcount
        ./wordcount-dynamic