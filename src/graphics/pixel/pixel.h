#ifndef GRAPHICS_PIXEL_H
#define GRAPHICS_PIXEL_H

#include "../../common/vec2d.h"
#include "../../window/frame.h"
#include <stdint.h>

/**
 * @brief Draws a pixel
 * 
 * @param frame The frame
 * @param pos The position
 * @param color The color
 * @return void
 * 
 */
void draw_pixel(Frame *frame, Vec2D pos, uint32_t color);

#endif // GRAPHICS_PIXEL_H