#ifndef GRAPHICS_LINE_C
#define GRAPHICS_LINE_C

#include "../common/vec2d.h"
#include "../window/window.h"
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Draws a line on the screen whether it be horizontal, vertical, or diagonal
 *
 * @param frame The frame
 * @param start The start position
 * @param end The end position
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_line(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
}

#endif // GRAPHICS_LINE_C