


all:
	c++ -o solar-system-sim -std=c++11 -lIrrlicht -lsfml-audio Main.cpp

.PHONY: clean
clean:
	rm -f solar-system-sim

