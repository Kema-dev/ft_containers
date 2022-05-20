#!/bin/zsh
make debug
./bin/debug.out > diff/false.txt
diff diff/true.txt diff/false.txt