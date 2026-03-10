CC = gcc
CFLAGS = -Wall

all: mycat myls

mycat: 

	$(CC) $(CFLAGS) /mycat/mycat.c -o mycat

myls: 

	$(CC) $(CFLAGS) /myls/myls.c -o myls

clean:

	rm -f mycat myls