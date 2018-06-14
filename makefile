OBJ=main.o http_analysis.o
main:${OBJ}
	gcc -o main ${OBJ}
clean:
	rm -f *.o
gdb:
	gcc -g -o main main.c http_analysis.c 
