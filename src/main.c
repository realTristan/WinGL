#include <windows.h>
#include "window/window.h"

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
    // Create and register a new window class
    register_window(L"window_class", hInstance);

    // Show the window
    show_window(L"window_class", "Window", hInstance);

    // Loop
    while (true)
    {
        open_message_context(message_callback);
    }
    return 0;
}