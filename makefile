CC=g++
CFLAGS=-Wall -std=c++11 -O3 -pthread
INCLUDE = -I .
LINK = -L .
Files = main.cpp ListTester.cpp VectorTester.cpp tests.cpp

all:
	${CC} ${Files} -o vectorVSlist ${CFLAGS} ${INCLUDE} ${LINK}