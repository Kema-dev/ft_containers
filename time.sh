#!/bin/zsh

if [ -z $1 ]
then
	echo "\e[31mUsage: $0 <number of iterations>\e[0m"
	exit 1
fi

case $(uname | tr '[:upper:]' '[:lower:]') in
	darwin*)
		shopt -s expand_aliases
		alias date=gdate
		;;
esac

echo "\e[35mCalculating execution time differences\e[0m"
mkdir diff 2> /dev/null
mkdir tmp 2> /dev/null
cat src/Main/main.cpp | sed -e "s/#if false/#if true/g" > tmp/main_true.cpp
cat src/Main/main.cpp | sed -e "s/#if true/#if false/g" > tmp/main_false.cpp

echo "\e[94mstl:\e[0m"
mv src/Main/main.cpp tmp/main_orig.cpp
mv tmp/main_true.cpp src/Main/main.cpp
make
echo "Running $1 iterations"
start=`date +%s%N`
./run.sh $1
end=`date +%s%N`
delta_stl=`expr $end - $start`
echo "Execution time was \e[33m$delta_stl nanoseconds\e[0m."

echo "\e[94mft:\e[0m"
mv src/Main/main.cpp tmp/main_true.cpp
mv tmp/main_false.cpp src/Main/main.cpp
make
echo "Running $1 iterations"
start=`date +%s%N`
./run.sh $1
end=`date +%s%N`
delta_ft=`expr $end - $start`
echo "Execution time was \e[33m$delta_ft nanoseconds\e[0m."

ratio=`perl -e "print $delta_ft / $delta_stl * 100 - 100"`
out=`printf "%.2f\n" $ratio`
echo -n "ft's execution time = stl's execution time "
if [ ${out:0:1} -eq "-" ]
then
	echo -e "\e[32m$out%\e[0m"
else
	echo -e "\e[31m+$out%\e[0m"
fi
