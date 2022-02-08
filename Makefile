.PHONY: all build clear launch

all: clear build launch

build:
	g++ --std=gnu++17 Easy/1.cpp -o task

launch:
	./task
