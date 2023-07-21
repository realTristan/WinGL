#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <stdbool.h>
#include <stdint.h>
#include "frame.h"

LRESULT CALLBACK WindowProcessMessage(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam);

#if RAND_MAX == 32767
#define Rand32() ((rand() << 16) | rand())
#else
#define Rand32() rand()
#endif

Frame *init_frame(int width, int height)
{
    Frame *frame = (Frame *)malloc(sizeof(Frame));
    *frame = (Frame){
        .width = 0,
        .height = 0,
        .pixels = NULL};

    frame->pixels = (uint32_t *)malloc(sizeof(uint32_t) * width * height);

    frame->bitmap_info->bmiHeader.biSize = sizeof(frame->bitmap_info->bmiHeader);
    frame->bitmap_info->bmiHeader.biPlanes = 1;
    frame->bitmap_info->bmiHeader.biBitCount = 32;
    frame->bitmap_info->bmiHeader.biCompression = BI_RGB;
    frame->device_context = CreateCompatibleDC(0);

    return frame;
}

void update_frame_bitmap(Frame *frame)
{
    if (frame->bitmap)
    {
        DeleteObject(frame->bitmap);
    }
    frame->bitmap = CreateDIBSection(
        frame->device_context,
        frame->bitmap_info,
        DIB_RGB_COLORS,
        (void **)&frame->pixels,
        0,
        0);
    SelectObject(frame->device_context, frame->bitmap);
}

void update_frame_pixels(Frame *frame, HWND window_handle)
{
    static unsigned int p = 0;
    frame->pixels[(p++) % (frame->width * frame->height)] = Rand32();
    frame->pixels[Rand32() % (frame->width * frame->height)] = 0;
    InvalidateRect(window_handle, NULL, FALSE);
    UpdateWindow(window_handle);
}

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
        exit(0);
        return 0;
    } break;

    case WM_PAINT:
    {
        static PAINTSTRUCT paint_struct;
        static HDC device_context;
        device_context = BeginPaint(window_handle, &paint_struct);
        BitBlt(
            device_context, 
            paint_struct.rcPaint.left, 
            paint_struct.rcPaint.top, 
            paint_struct.rcPaint.right - paint_struct.rcPaint.left, 
            paint_struct.rcPaint.bottom - paint_struct.rcPaint.top, 
            frame->device_context, 
            paint_struct.rcPaint.left, 
            paint_struct.rcPaint.top, 
            SRCCOPY);
    } break;

    case WM_SIZE:
    {
        frame->bitmap_info->bmiHeader.biWidth = LOWORD(lParam);
        frame->bitmap_info->bmiHeader.biHeight = HIWORD(lParam);
        update_frame_bitmap(frame);
        frame->width = LOWORD(lParam);
        frame->height = HIWORD(lParam);
    } break;

    default:
    {
        return DefWindowProc(window_handle, message, wParam, lParam);
    }
    break;
    }
    return 0;
}

HWND init_wnd_handle(const wchar_t *class_name, char *title, HINSTANCE hInstance)
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
    return window_handle;
}

WNDCLASS *init_wnd_class(const wchar_t *class_name, HINSTANCE hInstance)
{
    WNDCLASS *window_class = (WNDCLASS *)malloc(sizeof(WNDCLASS));
    *window_class = (WNDCLASS){0};

    window_class->lpszClassName = (PCSTR)class_name;
    window_class->lpfnWndProc = WindowProcessMessage;
    window_class->hInstance = hInstance;

    RegisterClass(window_class);
    return window_class;
}

void update_message(MSG message)
{
    while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}

void open_message_context(void (*function)(MSG))
{
    MSG message;
    while (true)
    {
        update_message(message);
        function(message);
    }
}

#endif // WINDOW_H