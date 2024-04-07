.PHONY: clean plot test

default:
	g++ -O3 main.cpp

test:
	./tester.sh

plot:
	gnuplot -p plot.pt
	
clean:
	rm a.out

