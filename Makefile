breakout: breakout.o
	g++ breakout.o -o breakout -lsfml-graphics -lsfml-window

breakout.o: breakout.cpp
	g++ -c breakout.cpp

clean:
	rm -f *.o breakout
