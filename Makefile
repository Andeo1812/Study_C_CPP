.PHONY: all build clear launch

all: clear build launch

LEVEL = Medium

NUMBER = 1

build:
	g++ --std=gnu++17 $(LEVEL)/$(NUMBER)/$(NUMBER).cpp -o task

launch:
	./task
