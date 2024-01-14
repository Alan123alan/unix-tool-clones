CFLAGS=-Wall -Wextra -pedantic -g
CC=cc

main:
	$(CC) $(CFLAGS) main.c	-o wcclone

unreadable:
	$(CC) $(CFLAGS) unreadable_gen.c -o unreadable_gen

clean:
	rm -rf wcclone wcclone.dSYM
	rm -rf unreadable.txt unreadable_gen unreadable_gen.dSYM
	rm -rf stdin_storage.txt
