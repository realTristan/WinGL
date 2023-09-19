#ifndef GRAPHICS_POLYGON_C
#define GRAPHICS_POLYGON_C

#include "polygon.h"
#include "../line/positioned.h"
#include "../../common/vec2d.h"
#include "../../window/frame.h"
#include <stdint.h>

void draw_polygon(Frame *frame, Vec2D *points, int num_points, uint32_t color, int thickness) {
    if (num_points < 3) return; // a polygon must have at least 3 points

    //drawing lines between consecutive points
    for (int i = 0; i < num_points - 1; ++i) {
        draw_positioned_line(frame, points[i], points[i + 1], color, thickness);
    }

    //drawing lines from the last point to the first
    draw_positioned_line(frame, points[num_points - 1], points[0], color, thickness);
}

#endif // GRAPHICS_POLYGON_C
