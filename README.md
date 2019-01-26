# Simple grep Tool

This is a basic program written in C to search for words in different set of files.

## Demo
```shell
# build program
$ make simple-grep
cc -Wall -g    simple-grep.c   -o simple-grep

# create a database
$ ./dbms db.dat c

# search for the words "this", "is", and "mehrdad"
# in the files listed in .filelist
this	: found in test.txt -> line: 1
this	: found in test.txt -> line: 2
is	: found in test.txt -> line: 1
is	: found in test.txt -> line: 2
mehrdad	: found in test1.txt -> line: 1
```
