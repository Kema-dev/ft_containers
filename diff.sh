#!/bin/zsh
mkdir diff 2> /dev/null
cat src/Main/main.cpp | sed -e "s/#if false/#if true/g" > src/Main/main.cpp.true
cat src/Main/main.cpp | sed -e "s/#if true/#if false/g" > src/Main/main.cpp.false
mv src/Main/main.cpp src/Main/main.cpp.orig
mv src/Main/main.cpp.true src/Main/main.cpp
make debug
./bin/debug.out > diff/true.txt
mv src/Main/main.cpp src/Main/main.cpp.old
mv src/Main/main.cpp.false src/Main/main.cpp
make debug
./bin/debug.out > diff/false.txt
rm src/Main/main.cpp
rm src/Main/main.cpp.old
mv src/Main/main.cpp.orig src/Main/main.cpp
diff diff/true.txt diff/false.txt > diff/diff.txt
rm diff/true.txt
rm diff/false.txt