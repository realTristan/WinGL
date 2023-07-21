all: link output execute

link:
	gcc -c src/window/window.c -o build/window.o
	gcc -c src/main.c -o build/main.o

output:
	gcc build/window.o build/main.o -o build/main.exe

execute:
	./build/main.exe