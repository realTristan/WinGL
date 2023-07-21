all: build execute

build:
	gcc -I"src" src/window/window.c src/window/events.c src/main.c -o build/main.exe -L"MinGW/lib" -lgdi32

execute:
	./build/main.exe
