#ifndef MAIN
#define MAIN

#include <windows.h>
#include <stdio.h>
#include "window/window.h"
#include "window/events.h"
#include "window/frame.h"
#include "common/vec2d.h"

// The frame
static Frame *frame;

/**
 * @brief Draws random pixels on the screen
 *
 * @param frame The frame
 * @return void
 */
void draw_line(Frame *frame)
{
    // Draw a white line with a length of 100 pixels and thickness of 5 pixels
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            uint32_t *pixel = frame_at(frame, (Vec2D){100 + i, 100 + j});
            *pixel = 0x00FFFFFF;
        }
    }

    // Update the window
    update_frame(frame);
}

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

    // Draw on the screen
    draw_line(frame);

    // If the window is resized
    if (event_resize(message))
    {
        size_frame(message.hwnd, frame);
    }
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
    HWND wnd_handle = init_wnd_handle(L"wnd_class", "Window", hInstance, nCmdShow);
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
gcc -I"src" src/window/window.c src/window/events.c src/main.c -o build/main.exe -L"MinGW/lib" -lgdi32
./build/main.exe
*/

#endif // MAIN