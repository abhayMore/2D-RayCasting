all: sfml-app
	./sfml-app

sfml-app: $(F2) Wall.o Ray.o
	g++ -std=c++17 $(F2) Wall.o Ray.o -o sfml-app -ltgui -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

Wall.o : Wall.cpp Wall.h
	g++ -std=c++17 -c Wall.cpp

Ray.o : Ray.cpp Ray.h
	g++ -std=c++17 -c Ray.cpp

$(F2) : $(F1) Wall.h Ray.h
		g++ -std=c++17 -c $(F1)

clean:
	rm -rf *o sfml-app
