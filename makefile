CC = gcc
CFLAGS = -Wall

all: mycat myls

mycat: 

	$(CC) $(CFLAGS) cat-util/mycat.c -o mycat

myls: 

	$(CC) $(CFLAGS) ls-util/myls.c -o myls

clean:

	rm -f mycat myls