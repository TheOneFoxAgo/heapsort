FILENAMES="Лучший Средний Худший"
.PHONY: clean plot test

default:
	g++ -O3 main.cpp counter.cpp

test:
	./tester.sh $(FILENAMES)

timeplot:
	gnuplot -p -c plot.pt "Время сортировки" 2 $(FILENAMES)

compplot:
	gnuplot -p -c plot.pt "Количество сравнений" 3 $(FILENAMES)

swapplot:
	gnuplot -p -c plot.pt "Количество перестановок" 4 $(FILENAMES)

clean:
	rm a.out

