breakout: breakout.o Paddle.o
	g++ breakout.o Paddle.o -o breakout -lsfml-graphics -lsfml-window

breakout.o: breakout.cpp
	g++ -c breakout.cpp

Paddle.o: Paddle.h Paddle.cpp
	g++ -c Paddle.cpp

clean:
	rm -f *.o breakout
