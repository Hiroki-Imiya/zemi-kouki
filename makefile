ziku: ziku.o 
	gcc -o ziku ziku.o
ziku.o: ziku.c
	gcc -c ziku.c