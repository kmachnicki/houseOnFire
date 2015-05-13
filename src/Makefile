CC = clang++
CFLAGS = -Wall -Wextra -std=c++11 -pthread -stdlib=libc++ -lc++abi -O3

TARGET = so2
SOURCE = Main.cpp FireSimulator.cpp Arsonist.cpp Firefighter.cpp House.cpp OutputWindow.cpp

all: $(TARGET)
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)


.PHONY: clean

clean:
	$(RM) $(TARGET)
