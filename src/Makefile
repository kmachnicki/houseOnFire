CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -stdlib=libc++ -lc++abi -O3

TARGET = so2
SOURCE = Main.cpp Arsonist.cpp Firefighter.cpp

all: $(TARGET)
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)


.PHONY: clean

clean:
	$(RM) $(TARGET)
