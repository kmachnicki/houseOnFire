CC = clang++
CFLAGS = -Wall -Wextra -std=c++11 -pthread -stdlib=libc++ -lc++abi -lncurses

TARGET = so2
SOURCE = Main.cpp Person.cpp Arsonist.cpp Firefighter.cpp FireSimulator.cpp  House.cpp Playground.cpp OutputWindow.cpp

all: $(TARGET)
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)


.PHONY: clean

clean:
	$(RM) $(TARGET)
