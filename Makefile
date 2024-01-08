CFLAGS=-Wall -Wextra -pedantic -g
CC=cc

main:
	$(CC) $(CFLAGS) main.c	-o wcclone
clean:
	rm -rf wcclone wcclone.dSYM
