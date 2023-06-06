output: main.o getAnswer.o ArrayList.o
	g++ ./lib/getAnswer.o ./lib/ArrayList.o ./lib/main.o -o ./bin/app.exe

ArrayList.o:
	g++ -c ./src/ArrayList.cpp -o ./lib/ArrayList.o

getAnswer.o: ArrayList.o
	g++ -c ./src/getAnswer.cpp -o ./lib/getAnswer.o

main.o: getAnswer.o
	g++ -c ./src/main.cpp -o ./lib/main.o
