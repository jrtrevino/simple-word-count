# simple-word-count

This program counts the number of `words`, `lines`, and `characters` within a provided file. If no file is provided as a command line argument, `STDIN` is used.

## Compiling

This repository contains a makefile inside of `src/`. On your machine, type

```
$ make
```
to compile the program.

## Running

To run this program (after compiling), type 

```
$ ./a.out [options] ... [file] ...
```

This will count the number of words, lines, and characters in `file` if no options are present. If multiple files are provided, metrics for all files are printed to `STDOUT` including a summation of all metrics.

### options

There are three available options for this program.
1. `-l`
2. `-w`
3. `-c`

Providing the `-l` flag signifies to only print the number of lines in a file. The `-w` and `-c` signify to only print the number of words or characters, respectively. Any combination of the three options can be provided.

## Cleaning

To clean object files, you can use the makefile once again. Type:

```
$ make clean
```

to remove any and all object files created by the makefile.
