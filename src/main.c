#include <windows.h>
#include "window/window.h"
#include "window/events.h"
#include "window/frame.h"
#include <stdio.h>

// The frame
static Frame *frame;

/**
 * @brief Generate a random 32 bit integer
 *
 * @return int The random integer
 */
#if RAND_MAX == 32767
#define Rand32() ((rand() << 16) | rand())
#else
#define Rand32() rand()
#endif

/**
 * @brief Draws random pixels on the screen
 *
 * @param frame The frame
 * @param window_handle The window handle
 * @return void
 */
void draw_rand_pixels(Frame *frame, HWND window_handle)
{
    /*static unsigned int p = 0;
    frame->pixels[(p++) % (frame->width * frame->height)] = Rand32();
    frame->pixels[Rand32() % (frame->width * frame->height)] = 100;*/
    
    // Set the frame pixels to black
    for (int i = 0; i < frame->width * frame->height; i++)
    {
        frame->pixels[i] = 0;
    }

    // Update the window
    InvalidateRect(window_handle, NULL, FALSE);
    UpdateWindow(window_handle);
}

/**
 * @brief Callback function for the message context
 *
 * @param message The message
 * @return void
 */
void message_callback(MSG message)
{
    // Draw on the screen
    draw_rand_pixels(frame, message.hwnd);

    // Handle the message events
    if (event_paint(message))
    {
        paint_frame(message.hwnd, frame);
    }

    if (event_resize(message))
    {
        resize_frame(message.hwnd, frame);
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
    // Initialize the frame
    frame = init_frame(800, 600);
    printf("Frame initialized\n");

    // Create and register a new window class
    WNDCLASS *wnd_class = init_wnd_class(L"window_class", hInstance);
    printf("Window class initialized\n");

    // Show the window
    HWND wnd_handle = init_wnd_handle(L"window_class", "Window", hInstance);
    printf("Window handle initialized\n");

    // Loop for handling messages
    while (true)
        open_message_context(message_callback);

    // Exit the program
    return 0;
}