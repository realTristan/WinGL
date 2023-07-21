#ifndef WINDOW_C
#define WINDOW_C

#include <windows.h>
#include <stdbool.h>
#include <stdint.h>
#include "frame.h"
#include "../common/vec2d.h"

/**
 * @brief Creates a frame
 * 
 * @param frame The frame
 * @param pos The position to get
 * @return uint32_t* 
 */
uint32_t *frame_at(Frame *frame, Vec2D pos)
{
    return &frame->pixels[pos.x + pos.y * frame->width];
}

/**
 * @brief Closes the window
 * 
 * @return void
 * 
 */
void close_wnd()
{
    PostQuitMessage(0);
}

/**
 * @brief Clears the window
 * 
 * @param frame The frame
 * @param color The color
 * @return void
 * 
 */
void clear_wnd(Frame *frame, uint32_t color)
{
    for (int i = 0; i < frame->width * frame->height; i++)
    {
        frame->pixels[i] = color;
    }
}

/**
 * @brief Get the wnd width object
 * 
 * @param wnd_handle The window handle
 * @return int 
 */
int get_wnd_width(HWND wnd_handle)
{
    RECT client_rect;
    GetClientRect(wnd_handle, &client_rect);
    return client_rect.right - client_rect.left;
}

/**
 * @brief Get the wnd height object
 * 
 * @param wnd_handle The window handle
 * @return int 
 */
int get_wnd_height(HWND wnd_handle)
{
    RECT client_rect;
    GetClientRect(wnd_handle, &client_rect);
    return client_rect.bottom - client_rect.top;
}

/**
 * @brief Get the wnd size object
 * 
 * @param wnd_handle The window handle
 * @return Vec2D 
 */
Vec2D get_wnd_size(HWND wnd_handle)
{
    RECT client_rect;
    GetClientRect(wnd_handle, &client_rect);
    return (Vec2D){client_rect.right - client_rect.left, client_rect.bottom - client_rect.top};
}

/**
 * @brief Updates the message
 * 
 * @param message The message
 */
void update_message(MSG *message)
{
    while (PeekMessage(message, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(message);
        DispatchMessage(message);
    }
}

/**
 * @brief Opens a message context
 * 
 * @param function The message callback function
 */
void open_message_context(void (*function)(MSG))
{
    MSG message;
    for (;;)
    {
        update_message(&message);
        function(message);
    }
}

/**
 * @brief Updates the frame via StretchDIBits
 * 
 * @param frame The frame
 */
void update_frame(Frame *frame)
{
    StretchDIBits(
        frame->device_context,
        0,
        0,
        frame->width,
        frame->height,
        0,
        0,
        frame->width,
        frame->height,
        frame->pixels,
        frame->bitmap_info,
        DIB_RGB_COLORS,
        SRCCOPY);
}

/**
 * @brief Sizes the frame
 * 
 * @param wnd_handle The window handle
 * @param frame The frame
 */
void size_frame(HWND wnd_handle, Frame *frame)
{
    // Get the new width/height
    Vec2D size = get_wnd_size(wnd_handle);
    frame->width = size.x;
    frame->height = size.y;

    // Update the bitmap info
    frame->bitmap_info->bmiHeader.biWidth = size.x;
    frame->bitmap_info->bmiHeader.biHeight = -size.y;

    // Update the bitmap
    update_frame(frame);
}

/**
 * @brief Initializes the frame
 * 
 * @param wnd_handle The window handle
 * @return Frame* 
 */
Frame *init_frame(HWND wnd_handle)
{
    Vec2D size = get_wnd_size(wnd_handle);
    Frame *frame = (Frame *)malloc(sizeof(Frame));
    *frame = (Frame){
        .width = size.x,
        .height = size.y,
        .pixels = NULL,
        .bitmap_info = (BITMAPINFO *)malloc(sizeof(BITMAPINFO)),
        .device_context = NULL};

    frame->pixels = (uint32_t *)malloc(sizeof(uint32_t) * size.x * size.y);
    frame->bitmap_info->bmiHeader.biSize = sizeof(frame->bitmap_info->bmiHeader);
    frame->bitmap_info->bmiHeader.biPlanes = 1;
    frame->bitmap_info->bmiHeader.biBitCount = 32;
    frame->bitmap_info->bmiHeader.biCompression = BI_RGB;
    frame->bitmap_info->bmiHeader.biWidth = size.x;
    frame->bitmap_info->bmiHeader.biHeight = -size.y;
    frame->device_context = GetDC(wnd_handle);

    return frame;
}

/**
 * @brief Initializes the window handle
 * 
 * @param class_name The window class name
 * @param title The window title
 * @param hInstance The instance of the program
 * @param nCmdShow The command show
 * @return HWND 
 */
HWND init_wnd_handle(const wchar_t *class_name, char *title, HINSTANCE hInstance, INT nCmdShow)
{
    // Initialize the wnd handle
    HWND wnd_handle = CreateWindow(
        (LPCSTR)class_name,
        (LPCSTR)title,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    // Show the wnd
    ShowWindow(wnd_handle, nCmdShow);
    return wnd_handle;
}

/**
 * @brief Window Process Message Callback
 * 
 * @param wnd_handle The window handle
 * @param message The message
 * @param wParam The wParam
 * @param lParam The lParam
 * @return LRESULT 
 */
LRESULT CALLBACK WindowProcessMessage(HWND wnd_handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_QUIT:
    case WM_DESTROY:
    {
        close_wnd();
        exit(0);
        return 0;
    }
    break;

    default:
    {
        return DefWindowProc(wnd_handle, message, wParam, lParam);
    }
    break;
    }
    return 0;
}

/**
 * @brief Initializes the window class
 * 
 * @param class_name The window class name
 * @param hInstance The instance of the program
 * @return WNDCLASS* 
 */
WNDCLASS *init_wnd_class(const wchar_t *class_name, HINSTANCE hInstance)
{
    WNDCLASS *wnd_class = (WNDCLASS *)malloc(sizeof(WNDCLASS));
    *wnd_class = (WNDCLASS){
        .style = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc = WindowProcessMessage,
        .cbClsExtra = 0,
        .cbWndExtra = 0,
        .hInstance = hInstance,
        .hIcon = LoadIcon(NULL, IDI_APPLICATION),
        .hCursor = LoadCursor(NULL, IDC_ARROW),
        .hbrBackground = (HBRUSH)(COLOR_WINDOW + 1),
        .lpszMenuName = NULL,
        .lpszClassName = (LPCSTR)class_name};

    RegisterClass(wnd_class);
    return wnd_class;
}

#endif // WINDOW_C