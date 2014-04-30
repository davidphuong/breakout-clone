breakout: breakout.o Paddle.o VisibleGameObject.o Ball.o GameObjectManager.o
	g++ breakout.o Paddle.o VisibleGameObject.o Ball.o GameObjectManager.o -o breakout -lsfml-graphics -lsfml-window

breakout.o: breakout.cpp
	g++ -c breakout.cpp

Paddle.o: Paddle.h Paddle.cpp
	g++ -c Paddle.cpp

VisibleGameObject.o: VisibleGameObject.h VisibleGameObject.cpp
	g++ -c VisibleGameObject.cpp

Ball.o: Ball.h Ball.cpp
	g++ -c Ball.cpp

GameObjectManager.o: GameObjectManager.h GameObjectManager.cpp
	g++ -c GameObjectManager.cpp

clean:
	rm -f *.o breakout
