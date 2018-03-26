prog: main.o MinMaxHeap.o MaxMinHeap.o
	g++ -g -Wall -std=c++11 main.o MinMaxHeap.o MaxMinHeap.o -o prog

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

MinMaxHeap.o: MinMaxHeap.cpp MinMaxHeap.h Heap.h
	g++ -g -Wall -std=c++11 -c MinMaxHeap.cpp

MaxMinHeap.o: MaxMinHeap.cpp MaxMinHeap.h Heap.h
	g++ -g -Wall -std=c++11 -c MaxMinHeap.cpp

clean:
	rm *.o prog
