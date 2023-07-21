#ifndef WINDOW_EVENTS_H
#define WINDOW_EVENTS_H

#include <windows.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Checks if the event is a quit event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_quit(MSG message)
{
    return message.message == WM_QUIT;
}

/**
 * @brief Checks if the event is a resize event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_resize(MSG message)
{
    return message.message == WM_SIZE;
}

/**
 * @brief Checks if the event is a keydown event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_keydown(MSG message)
{
    return message.message == WM_KEYDOWN;
}

/**
 * @brief Checks if the event is a keyup event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_keyup(MSG message)
{
    return message.message == WM_KEYUP;
}

/**
 * @brief Checks if the event is a keypress event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_keypress(MSG message)
{
    return message.message == WM_CHAR;
}

/**
 * @brief Checks if the event is a mousemove event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mousemove(MSG message)
{
    return message.message == WM_MOUSEMOVE;
}

/**
 * @brief Checks if the event is a mousedown event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mousedown(MSG message)
{
    return message.message == WM_LBUTTONDOWN;
}

/**
 * @brief Checks if the event is a mouseup event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mouseup(MSG message)
{
    return message.message == WM_LBUTTONUP;
}

/**
 * @brief Checks if the event is a mousewheel event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mousewheel(MSG message)
{
    return message.message == WM_MOUSEWHEEL;
}

/**
 * @brief Checks if the event is a mousehover event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mousehover(MSG message)
{
    return message.message == WM_MOUSEHOVER;
}

/**
 * @brief Checks if the event is a mouseleave event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mouseleave(MSG message)
{
    return message.message == WM_MOUSELEAVE;
}

#endif // WINDOW_EVENTS_H