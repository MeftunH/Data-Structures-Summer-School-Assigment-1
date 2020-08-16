hepsi: hazirlik derle calistir
hazirlik:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Iterator.o -c ./src/Iterator.cpp
	g++ -I ./include/ -o ./lib/CircularDoublyLinkedList.o -c ./src/CircularDoublyLinkedList.cpp
derle:	
	g++ -I ./include/ -o ./bin/Test ./lib/Dugum.o ./lib/Iterator.o ./lib/CircularDoublyLinkedList.o ./src/Test.cpp
calistir:
	./bin/Test