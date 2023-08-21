compile:./main.cpp
	g++ -c ./main.cpp
	g++ *.o -o app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

run:
	./app

clear:
	rm app
	rm *.o