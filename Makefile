.PHONY: run print clean debug

default: a.out

run: a.out
	./a.out a out.txt

print: out.txt
	cat out.txt

debug:
	g++ -g main.cpp
	lldb a.out a out.txt
	rm a.out

a.out:
	g++ -O3 main.cpp

out.txt:
	./a.out a out.txt

clean:
	rm a.out

