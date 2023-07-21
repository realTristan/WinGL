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
uint32_t *frame_at(Frame *frame, Vec2D pos);

/**
 * @brief Closes the window
 * 
 * @return void
 * 
 */
void close_wnd();

/**
 * @brief Clears the window
 * 
 * @param frame The frame
 * @param color The color
 * @return void
 * 
 */
void clear_wnd(Frame *frame, uint32_t color);

/**
 * @brief Get the wnd width object
 * 
 * @param wnd_handle The window handle
 * @return int 
 */
int get_wnd_width(HWND wnd_handle);

/**
 * @brief Get the wnd height object
 * 
 * @param wnd_handle The window handle
 * @return int 
 */
int get_wnd_height(HWND wnd_handle);

/**
 * @brief Get the wnd size object
 * 
 * @param wnd_handle The window handle
 * @return Vec2D 
 */
Vec2D get_wnd_size(HWND wnd_handle);

/**
 * @brief Updates the message
 * 
 * @param message The message
 */
void update_message(MSG *message);

/**
 * @brief Opens a message context
 * 
 * @param function The message callback function
 */
void open_message_context(void (*function)(MSG));

/**
 * @brief Updates the frame via StretchDIBits
 * 
 * @param frame The frame
 */
void update_frame(Frame *frame);

/**
 * @brief Sizes the frame
 * 
 * @param wnd_handle The window handle
 * @param frame The frame
 */
void size_frame(HWND wnd_handle, Frame *frame);

/**
 * @brief Initializes the frame
 * 
 * @param wnd_handle The window handle
 * @return Frame* 
 */
Frame *init_frame(HWND wnd_handle);

/**
 * @brief Initializes the window handle
 * 
 * @param class_name The window class name
 * @param title The window title
 * @param hInstance The instance of the program
 * @param nCmdShow The command show
 * @return HWND 
 */
HWND init_wnd_handle(const wchar_t *class_name, char *title, HINSTANCE hInstance, INT nCmdShow);

/**
 * @brief Window Process Message Callback
 * 
 * @param wnd_handle The window handle
 * @param message The message
 * @param wParam The wParam
 * @param lParam The lParam
 * @return LRESULT 
 */
LRESULT CALLBACK WindowProcessMessage(HWND wnd_handle, UINT message, WPARAM wParam, LPARAM lParam);

/**
 * @brief Initializes the window class
 * 
 * @param class_name The window class name
 * @param hInstance The instance of the program
 * @return WNDCLASS* 
 */
WNDCLASS *init_wnd_class(const wchar_t *class_name, HINSTANCE hInstance);

#endif // WINDOW_C