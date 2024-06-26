FILENAMES="Лучший Средний Худший"
.PHONY: clean test timeplot compplot swapplot 

default:
	g++ -O3 main.cpp counter.cpp

test:
	./tester.sh $(FILENAMES)

timeplot:
	gnuplot -p -c plot.pt "Время сортировки" 2 $(FILENAMES)

compplot:
	gnuplot -p -c plot.pt "Количество сравнений" 3 $(FILENAMES)

swapplot:
	gnuplot -p -c plot.pt "Количество обменов" 4 $(FILENAMES)

clean:
	rm a.out

