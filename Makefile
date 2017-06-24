all:compile run
compile:
	
	g++ -I ./include/ -o ./bin/test ./src/encrypt.cpp ./src/test.cpp
	g++ -I ./include/ -o ./bin/test1 ./src/decrypt.cpp ./src/test2.cpp
run:
	./bin/test
	./bin/test1
