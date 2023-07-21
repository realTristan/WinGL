#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <stdbool.h>

bool event_quit(MSG message)
{
    return message.message == WM_QUIT;
}

void close_window()
{
    PostQuitMessage(0);
}

LRESULT CALLBACK WindowProcessMessage(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_QUIT:
    case WM_DESTROY:
    {
        close_window();
        return 0;
    }
    break;

    default:
    {
        return DefWindowProc(window_handle, message, wParam, lParam);
    }
    break;
    }
    return 0;
}

void show_window(const wchar_t *class_name, char *title, HINSTANCE hInstance)
{
    // Initialize the window handle
    HWND window_handle = CreateWindow(
        (PCSTR)class_name,
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    // Show the window
    ShowWindow(window_handle, SW_SHOW);
}

void register_window(const wchar_t *class_name, HINSTANCE hInstance)
{
    WNDCLASS *window_class = (WNDCLASS *)malloc(sizeof(WNDCLASS));
    *window_class = (WNDCLASS){0};

    window_class->lpszClassName = (PCSTR)class_name;
    window_class->lpfnWndProc = WindowProcessMessage;
    window_class->hInstance = hInstance;

    RegisterClass(window_class);
}

void update_message(MSG *message)
{
    while (PeekMessage(message, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(message);
        DispatchMessage(message);
    }
}

void open_message_context(void (*function)(MSG))
{
    MSG message;
    while (true)
    {
        update_message(&message);
        function(message);
    }
}

#endif // WINDOW_H