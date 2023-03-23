all: test

compile:
	@echo Compiling
	g++ -c requests.cpp -I /usr/include/x86_64-linux-gnu/
	g++ -c parser.cpp
	g++ -c main.cpp


build: compile
	@echo Building
	g++ -o main.exe requests.o parser.o main.o -lcurl


test: build
	@echo Testing
	./main.exe

clean:
	rm -f *.o *.exe 
