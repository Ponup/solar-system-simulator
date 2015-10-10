
CCFLAGS=-std=c++11 -lIrrlicht -lsfml-audio -Wall -pedantic
EXECUTABLE=solar-system-sim

all:
	c++ -o $(EXECUTABLE) $(CCFLAGS) Main.cpp

.PHONY: clean
clean:
	rm -f $(EXECUTABLE)

