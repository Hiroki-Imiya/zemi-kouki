ziku: ziku.o shaft.o koubun.o
	gcc -o ziku ziku.o shaft.o
	gcc -o koubun koubun.o
ziku.o: ziku.c
	gcc -c ziku.c
shaft.o:shaft.c
	gcc -c shaft.c
koubun.o:koubun.c
	gcc -c koubun.c
clean:
	rm -f ziku