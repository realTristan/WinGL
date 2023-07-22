#ifndef MAIN
#define MAIN

#include <windows.h>
#include <stdio.h>
#include "window/window.h"
#include "window/events.h"
#include "window/frame.h"
#include "common/vec2d.h"
#include "graphics/line/positioned.h"
#include "graphics/line/angled.h"
#include "graphics/circle/circle.h"

// The frame
static Frame *frame;

/**
 * @brief Callback function for the message context
 *
 * @param message The message
 * @return void
 */
void message_callback(MSG message)
{
    // Clear the screen to black
    clear_wnd(frame, 0x00000000);

    // Draw positioned lines on the screen
    draw_positioned_line(frame, (Vec2D){100, 300}, (Vec2D){200, 480}, 0x00FFFFFF, 5); // graphics/line.h
    draw_positioned_line(frame, (Vec2D){600, 100}, (Vec2D){600, 300}, 0x00FFFFFF, 5); // graphics/line.h
    draw_positioned_line(frame, (Vec2D){300, 100}, (Vec2D){500, 100}, 0x00FFFFFF, 5); // graphics/line.h

    // Draw angled lines on the screen
    draw_angled_line(frame, (Vec2D){400, 400}, 45, 100, 0x00FFFFFF, 5); // graphics/line.h
    draw_angled_line(frame, (Vec2D){200, 600}, 0, 100, 0x00FFFFFF, 5); // graphics/line.h
    draw_angled_line(frame, (Vec2D){800, 500}, 135, 100, 0x00FFFFFF, 5); // graphics/line.h

    // Draw a circle on the screen
    draw_circle(frame, (Vec2D){400, 400}, 100, 5, 100); // graphics/circle.h

    // If the window is resized
    if (event_resize(message))
    {
        size_frame(message.hwnd, frame); // need to call update_frame afterwards
    }

    // Update the frame
    update_frame(frame);
}

/**
 * @brief The entry point of the program
 *
 * @param hInstance The instance of the program
 * @param hPrevInstance The previous instance of the program
 * @param lpCmdLine The command line arguments
 * @param nCmdShow The command show
 * @return int The exit code
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    // Create and register a new window class
    WNDCLASS *wnd_class = init_wnd_class(L"wnd_class", hInstance);
    printf("Window class initialized\n");

    // Show the wnd
    HWND wnd_handle = init_wnd_handle(L"wnd_class", "WinGL - Win32 Graphics Library", hInstance, nCmdShow);
    printf("Window handle initialized\n");

    // Initialize the frame
    frame = init_frame(wnd_handle);
    printf("Frame initialized\n");

    // Loop for handling messages
    open_message_context(message_callback);

    // Exit the program
    return 0;
}

/*
gcc -I"src" src/window/window.c src/graphics/circle/circle.c src/graphics/line/angled.c src/graphics/line/positioned.c src/window/events.c src/main.c -o build/main.exe -L"MinGW/lib" -lgdi32
./build/main.exe
*/

#endif // MAIN