#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <stdbool.h>

LRESULT CALLBACK WindowProcessMessage(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam);

bool event_quit(MSG message);

void show_window(const wchar_t *class_name, char *title, HINSTANCE hInstance);
void register_window(const wchar_t *class_name, HINSTANCE hInstance);

void get_message(MSG *message);
void open_message_context(void (*function)(MSG));

#endif // WINDOW_H