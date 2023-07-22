#ifndef GRAPHICS_PIXEL_C
#define GRAPHICS_PIXEL_C

#include "../../window/window.h"
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
void draw_pixel(Frame *frame, Vec2D pos, uint32_t color)
{
    // Get the pixel position
    uint32_t *pixel = frame_at(frame, pos);
    *pixel = color;
}

#endif // GRAPHICS_PIXEL_C