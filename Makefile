.PHONY: all build clear launch

all: clear build launch

build:
	g++ --std=gnu++17 Medium/1/1.cpp -o task

launch:
	./task
