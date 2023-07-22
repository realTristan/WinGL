#ifndef GRAPHICS_LINE_ANGLED_C
#define GRAPHICS_LINE_ANGLED_C

#include "../../common/vec2d.h"
#include "../../window/frame.h"
#include <stdint.h>

/**
 * @brief Draws a line on the screen
 *
 * @param frame The frame
 * @param start The start position
 * @param angle The angle of the line
 * @param length The length of the line
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_angled_line(Frame *frame, Vec2D start, float angle, float length, uint32_t color, int width);

#endif // GRAPHICS_LINE_ANGLED_C