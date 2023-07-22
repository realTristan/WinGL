#ifndef GRAPHICS_ANGLED_LINE_C
#define GRAPHICS_ANGLED_LINE_C

#include "../common/vec2d.h"
#include "../window/frame.h"
#include "positioned_line.h"
#include <stdint.h>
#include <math.h>

#define M_PI 3.14159265358979323846

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
void draw_angled_line(Frame *frame, Vec2D start, float angle, float length, uint32_t color, int width)
{
    // Convert the angle to radians
    angle = angle * (M_PI / 180);

    // Calculate the end position
    Vec2D end = (Vec2D){start.x + length, start.y + length * sin(angle)};
    
    // Draw the line
    draw_positioned_line(frame, start, end, color, width);
}

#endif // GRAPHICS_ANGLED_LINE_C