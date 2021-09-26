all: sfml-app
	./sfml-app

sfml-app: $(F2) Wall.o Ray.o segment.o Vector2.o
	g++ -std=c++17 $(F2) Wall.o Ray.o segment.o Vector2.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

Wall.o : Wall.cpp Wall.h
	g++ -std=c++17 -c Wall.cpp

Ray.o : Ray.cpp Ray.h
	g++ -std=c++17 -c Ray.cpp

Vector2.o : Vector2.cpp Vector2.h
	g++ -std=c++17 -c Vector2.cpp
	
segment.o : segment.cpp segment.h
	g++ -std=c++17 -c segment.cpp
	
$(F2) : $(F1) Wall.h Ray.h segment.h Vector2.h
		g++ -std=c++17 -c $(F1)

clean:
	rm -rf *o sfml-app
