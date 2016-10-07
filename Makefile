#
#
# use g++ as c++ compiler
# -std=c++11   - use c++11 features
#
CC=g++ -std=c++11
#
# -Wall : print out all compiler warning message
# -I    : include library file contains .h files
# include mySQL .h 
# CFLAGS = -c -Wall -I/usr/include/mysql 
# 
# To see all the g++ option, use man g++
#

CFLAGS = -c -Wall -I/usr/include/mysql 
LFLAGS = -L/usr/lib/mysql -lmysqlclient

all: checkIn

checkIn: checkIn.o
	$(CC) $(LFLAGS) checkIn.o -o checkIn 

checkIn.o: checkIn.cpp checkIn.h
	$(CC) $(CFLAGS) checkIn.cpp

clean:
	\rm *.o checkIn

run:
	./checkIn
