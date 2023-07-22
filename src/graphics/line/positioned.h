#ifndef GRAPHICS_LINE_POSITIONED_H
#define GRAPHICS_LINE_POSITIONED_H

#include "../../common/vec2d.h"
#include "../../window/frame.h"

/**
 * @brief Draws a line on the screen
 *
 * @param frame The frame
 * @param start The start position
 * @param end The end position
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_positioned_line(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width);

#endif // GRAPHICS_LINE_POSITIONED_H