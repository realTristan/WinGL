#ifndef GRAPHICS_CIRCLE_H
#define GRAPHICS_CIRCLE_H

#include "../../window/frame.h"
#include "../../common/vec2d.h"

/**
 * @brief Draws a circle on the screen
 *
 * @param frame The frame
 * @param pos The position of the circle
 * @param radius The radius of the circle
 * @param width The width of the line
 * @param sides The amount of sides
 * @return void
 */
void draw_circle(Frame *frame, Vec2D pos, float radius, int width, int sides);

#endif // GRAPHICS_CIRCLE_H