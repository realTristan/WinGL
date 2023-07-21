#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <stdbool.h>
#include <stdint.h>
#include "frame.h"

Frame *init_frame(int width, int height);
void update_frame_bitmap(Frame *frame);
void paint_frame(HWND window_handle, Frame *frame);
void resize_frame(HWND window_handle, Frame *frame);

LRESULT CALLBACK WindowProcessMessage(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam);
HWND init_wnd_handle(const wchar_t *class_name, char *title, HINSTANCE hInstance);
WNDCLASS *init_wnd_class(const wchar_t *class_name, HINSTANCE hInstance);

void update_message(MSG message);
void open_message_context(void (*function)(MSG));

void close_window();

#endif // WINDOW_H