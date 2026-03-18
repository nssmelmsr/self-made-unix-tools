CC = gcc
CFLAGS = -Wall

all: mycat myls mywc myps

myps:

	$(CC) $(CFLAGS) ps-util/myps.c -o myps

mycat: 

	$(CC) $(CFLAGS) cat-util/mycat.c -o mycat

myls: 

	$(CC) $(CFLAGS) ls-util/myls.c -o myls

mywc: 

	$(CC) $(CFLAGS) wc-util/mywc.c -o mywc

clean:

	rm -f mycat myls mywc