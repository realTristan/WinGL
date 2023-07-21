#include <windows.h>
#include "window/window.h"

/**
 * @brief The frame
 *
 */
static Frame *frame;

/**
 * @brief Callback function for the message context
 *
 * @param message The message
 * @return void
 */
void message_callback(MSG message)
{
    if (event_quit(message))
    {
        close_window();
        exit(0);
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

    // Create and register a new window class
    WNDCLASS *wnd_class = init_wnd_class(L"window_class", hInstance);

    // Show the window
    HWND wnd_handle = init_wnd_handle(L"window_class", "Window", hInstance);

    // Loop
    while (true)
    {
        open_message_context(message_callback);
        update_frame_pixels(frame, wnd_handle);
    }
    return 0;
}