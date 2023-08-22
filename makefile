compile:./main.cpp
	g++ -c ./main.cpp ./source/*.cpp 
	g++ *.o -o app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

run:
	./app

clear:
	rm -f app
	rm -f *.o