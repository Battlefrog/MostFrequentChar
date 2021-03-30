all: main
	
doc: Doxyfile ./src/main.cpp ./include/example.hpp
	doxygen Doxyfile
	@echo "Documentation extraction complete."
 
main: ./src/main.cpp
	g++ -g -Wall ./src/main.cpp -o ./bin/main

clean:
	rm -rf ./doc/*
	rm -rf ./bin/*
