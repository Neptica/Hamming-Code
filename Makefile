
output: compiled/main.o compiled/functions.o
	g++ compiled/main.o compiled/functions.o -o output

compiled/main.o: main.cpp
	g++ -c main.cpp -o compiled/main.o

compiled/functions.o: functions.cpp
	g++ -c functions.cpp -o compiled/functions.o

clean: 
	rm compiled/*.o output
