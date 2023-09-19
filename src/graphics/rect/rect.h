#ifndef GRAPHICS_RECT_H
#define GRAPHICS_RECT_H

#include "../../common/vec2d.h"
#include "../../window/frame.h"
#include <stdint.h>

/**
 * @brief draws a rectangle on the screen
 *
 * @param frame the frame where to draw the rectangle
 * @param top_left the top left corner of the rectangle
 * @param size the size of the rectangle (width x height)
 * @param color the color of the rectangle
 * @param thickness the thickness of the rectangle's border
 * @return void
 */
void draw_rectangle(Frame *frame, Vec2D top_left, Vec2D size, uint32_t color, int thickness);

#endif // GRAPHICS_RECT_H
