ziku: ziku.o shaft.o
	gcc -o ziku ziku.o shaft.o
ziku.o: ziku.c
	gcc -c ziku.c
shaft.o:shaft.c
	gcc -c shaft.c
clean:
	rm -f ziku