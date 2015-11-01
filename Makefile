
UNAME:=$(shell uname -s)

CC=c++
CCFLAGS=-std=c++11 -g -Wall -pedantic -Wno-nested-anon-types  -I/usr/local/Cellar/irrlicht/1.8.1/include -I/usr/local/Cellar/sfml/2.3_1/include

LIBS=-lIrrlicht -lsfml-audio 
ifeq ($(UNAME),Darwin)
LIBS+=-framework OpenGL -framework Cocoa -framework IOKit -L/usr/local/Cellar/irrlicht/1.8.1/lib -L/usr/local/Cellar/sfml/2.3_1/lib
endif

TARGET=solar-system-sim
SRCS=CustomEventHandler.cpp PlanetBuilder.cpp PlanetFactory.cpp Path.cpp Main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

$(TARGET): $(OBJS) 
	$(CC) $(LIBS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

