breakout: breakout.o Paddle.o VisibleGameObject.o Ball.o
	g++ breakout.o Paddle.o VisibleGameObject.o Ball.o -o breakout -lsfml-graphics -lsfml-window

breakout.o: breakout.cpp
	g++ -c breakout.cpp

Paddle.o: Paddle.h Paddle.cpp
	g++ -c Paddle.cpp

VisibleGameObject.o: VisibleGameObject.h VisibleGameObject.cpp
	g++ -c VisibleGameObject.cpp

Ball.o: Ball.h Ball.cpp
	g++ -c Ball.cpp

clean:
	rm -f *.o breakout
