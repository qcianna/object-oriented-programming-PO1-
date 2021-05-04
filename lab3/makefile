main: main.o OneWayList.o Node.o
	g++ main.o OneWayList.o Node.o -Wall -g -o lab

OneWayList.o: OneWayList.cpp
	g++ -c OneWayList.cpp

Node.o: Node.cpp
	g++ -c Node.cpp
	
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf a.out