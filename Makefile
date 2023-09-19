all: output execute

output:
	gcc -I"src" src/window/window.c src/graphics/line.c src/window/events.c src/main.c -o build/main -L"MinGW/lib" -lgdi32

execute:
	./build/main
