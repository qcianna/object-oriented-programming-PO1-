main: main.o func.o
	g++ main.o func.o  -Wall -g -o lab

func.o: func.cpp
	g++ -c func.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf a.out