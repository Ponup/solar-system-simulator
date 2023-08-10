
UNAME:=$(shell uname -s)

CC=c++
CCFLAGS=-std=c++17 -g -Wall -pedantic -Wno-nested-anon-types

LIBS=-lIrrlicht -lsfml-audio -lsfml-system
ifeq ($(UNAME),Darwin)
LIBS+=-framework OpenGL -framework Cocoa -framework IOKit
endif

TARGET=solar-system-sim
SRCS=CustomEventHandler.cpp PlanetBuilder.cpp PlanetFactory.cpp Path.cpp Main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

$(TARGET): $(OBJS) 
	$(CC) $(OBJS) $(LIBS) -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

