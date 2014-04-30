breakout: breakout.o Paddle.o VisibleGameObject.o Ball.o GameObjectManager.o Block.o BlockManager.o
	g++ breakout.o Paddle.o VisibleGameObject.o Ball.o GameObjectManager.o Block.o BlockManager.o -o breakout -lsfml-graphics -lsfml-window

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

Block.o: Block.h Block.cpp
	g++ -c Block.cpp

BlockManager.o: BlockManager.h BlockManager.cpp
	g++ -c BlockManager.cpp

clean:
	rm -f *.o breakout
