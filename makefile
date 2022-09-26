all: ferreira_p2.o
	g++ -g ferreira_p2.o -o ferreira_p2

ferreira_p2.o: ferreira_p2.cpp
	g++ -g -c ferreira_p2.cpp

clean:
	rm ferreira_p2 *.o