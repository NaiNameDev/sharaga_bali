.PHONY = ct

ct: 
	g++ main.cpp
	./a.out
	rm a.out
