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
bool event_quit(MSG message);

/**
 * @brief Checks if the event is a resize event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_resize(MSG message);

/**
 * @brief Checks if the event is a keydown event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_keydown(MSG message);

/**
 * @brief Checks if the event is a keyup event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_keyup(MSG message);

/**
 * @brief Checks if the event is a keypress event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_keypress(MSG message);

/**
 * @brief Checks if the event is a mousemove event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mousemove(MSG message);

/**
 * @brief Checks if the event is a mousedown event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mousedown(MSG message);

/**
 * @brief Checks if the event is a mouseup event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mouseup(MSG message);

/**
 * @brief Checks if the event is a mousewheel event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mousewheel(MSG message);

/**
 * @brief Checks if the event is a mousehover event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mousehover(MSG message);

/**
 * @brief Checks if the event is a mouseleave event
 * 
 * @param message The message
 * @return true 
 * @return false 
 */
bool event_mouseleave(MSG message);

#endif // WINDOW_EVENTS_H