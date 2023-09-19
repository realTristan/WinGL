#ifndef GRAPHICS_POLYGON_H
#define GRAPHICS_POLYGON_H

#include "../../common/vec2d.h"
#include "../../window/frame.h"
#include <stdint.h>

/**
 * @brief draws a polygon on the screen.
 *
 * @param frame frame where to draw the polygon
 * @param points an array of Vec2D points to represent the vertices of the polygon
 * @param num_points number of points in the array define the polygon's vertices
 * @param color color of the polygon's border
 * @param thickness thickness of polygon's border
 * @return void
 */
void draw_polygon(Frame *frame, Vec2D *points, int num_points, uint32_t color, int thickness);

#endif // GRAPHICS_POLYGON_H
