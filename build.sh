#! /bin/sh
rm -rf bin/out
gcc -I headers/ sources/student.c sources/main.c -o bin/out
bin/out

