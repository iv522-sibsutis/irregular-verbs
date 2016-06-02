func: main.o func.o
	gcc -Wall -o a.out main.o func.o 

test:
	gcc -Wall -o ctest ctest.c
	
main.o: main.c
	gcc -Wall -c main.c 

func.o: func.c 
	gcc -Wall -c func.c 

.PHONY: clean

clean:
	rm -rf a.out ctest *.o
