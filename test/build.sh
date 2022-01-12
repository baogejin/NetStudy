cd ../common
./build.sh
cd ../test
g++ -c -g -std=c++11 *.cpp
g++ -o svr svr.o ../common/BSocket.o
g++ -o cli cli.o ../common/BSocket.o
