OBJ=main.o
main:${OBJ}
	gcc -o main ${OBJ}
clean:
	rm -f *.o
