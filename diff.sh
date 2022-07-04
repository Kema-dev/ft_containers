#!/bin/zsh
mkdir diff 2> /dev/null
mkdir tmp 2> /dev/null
cat src/Main/main.cpp | sed -e "s/#if false/#if true/g" > tmp/main_true.cpp
cat src/Main/main.cpp | sed -e "s/#if true/#if false/g" > tmp/main_false.cpp
mv src/Main/main.cpp tmp/main_orig.cpp
mv tmp/main_true.cpp src/Main/main.cpp
make clean
make debug
./bin/debug.out > diff/true.txt
rm src/Main/main.cpp
mv tmp/main_false.cpp src/Main/main.cpp
make clean
make debug
./bin/debug.out > diff/false.txt
rm src/Main/main.cpp
echo "- : std\n+ : ft" > diff/std_vs_ft.diff
diff -u diff/true.txt diff/false.txt >> diff/std_vs_ft.diff
rm diff/true.txt diff/false.txt
mv tmp/main_orig.cpp src/Main/main.cpp
rm -r tmp