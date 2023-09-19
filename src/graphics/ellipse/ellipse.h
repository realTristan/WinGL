#ifndef GRAPHICS_ELLIPSE_H
#define GRAPHICS_ELLIPSE_H

#include "../../common/vec2d.h"
#include "../../window/frame.h"
#include <stdint.h>

/**
 * @brief draws an ellipse on the screen.
 *
 * @param frame frame where to draw the ellipse
 * @param center center position of the ellipse
 * @param rx horizontal radius of the ellipse
 * @param ry vertical radius of the ellipse
 * @param color color of the ellipse's border
 * @param thickness thickness of the ellipse's border
 * @return void
 */
void draw_ellipse(Frame *frame, Vec2D center, float rx, float ry, uint32_t color, int thickness);

#endif // GRAPHICS_ELLIPSE_H
