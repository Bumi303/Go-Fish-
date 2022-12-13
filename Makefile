CC=g++ -std=c++11 -g
EXE_FILE=r

all: $(EXE_FILE)

$(EXE_FILE): card.o  deck.o  hand.o  player.o  game.o  card.h deck.h hand.h player.h game.h driver.cpp
	$(CC) card.o deck.o hand.o player.o game.o driver.cpp -o $(EXE_FILE)
	
card.o: card.h card.cpp
	$(CC) -c card.cpp

deck.o: deck.h deck.cpp
	$(CC) -c deck.cpp
	
hand.o: hand.h hand.cpp
	$(CC) -c hand.cpp
	
player.o: player.h player.cpp
	$(CC) -c player.cpp
	
game.o: game.h game.cpp
	$(CC) -c game.cpp

clean:
	rm -f *.o $(EXE_FILE)
