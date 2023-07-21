#ifndef WINDOW_EVENTS_C
#define WINDOW_EVENTS_C

#include <windows.h>
#include <stdbool.h>
#include <stdio.h>

bool event_quit(MSG message)
{
    return message.message == WM_QUIT;
}

bool event_paint(MSG message)
{
    return message.message == WM_PAINT;
}

bool event_resize(MSG message)
{
    return message.message == WM_SIZE;
}

#endif // WINDOW_EVENTS_C