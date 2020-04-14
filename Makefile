
all: BestFirstSearch

BestFirstSearch: BestFirstSearch.o
	g++ BestFirstSearch.o -g -Wall -o $@

BestFirstSearch.o: BestFirstSearch.cpp
	g++ -c -g -Wall BestFirstSearch.cpp

clean:
	rm -f BestFirstSearch *.o
