
CC=g++ -std=c++11


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
	./checkIn Fall2016.csv
