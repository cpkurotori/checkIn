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

checkIn: checkIn.o checkInNew.o checkInReturn.o DotSlash.o
	$(CC) checkIn.o checkInNew.o checkInReturn.o DotSlash.o -o checkIn $(LFLAGS)

checkIn.o: checkIn.cpp checkIn.h
	$(CC) $(CFLAGS) checkIn.cpp

checkInNew.o: checkInNew.cpp checkIn.h
	$(CC) $(CFLAGS) checkInNew.cpp

checkInReturn.o: checkInReturn.cpp checkIn.h
	$(CC) $(CFLAGS) checkInReturn.cpp

DotSlash.o: DotSlash.cpp checkIn.h
	$(CC) $(CFLAGS) DotSlash.cpp

clean:
	rm *.o checkIn

run:
	./checkIn
