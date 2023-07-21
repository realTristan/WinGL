#ifndef WINDOW_EVENTS_H
#define WINDOW_EVENTS_H

#include <windows.h>
#include <stdbool.h>

bool event_quit(MSG message);

bool event_paint(MSG message);

bool event_resize(MSG message);

#endif // WINDOW_EVENTS_H