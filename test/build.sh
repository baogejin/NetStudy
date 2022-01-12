cd ../common
./build.sh
cd ../test
g++ -c -g -std=c++11 *.cpp
g++ -o svr svr.o ../common/*.o
g++ -o cli cli.o ../common/*.o
