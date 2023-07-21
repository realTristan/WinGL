#ifndef GRAPHICS_LINE
#define GRAPHICS_LINE

#include "common/vec2d.h"
#include "window/frame.h"
#include <stdint.h>

/**
 * @brief Draws a line on the screen in the x direction
 *
 * @param frame The frame
 * @param start The start position
 * @param end The end position
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_line_x(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
    for (int k = 0; k < width; k++)
    {
        for (int i = 0; i < start.x - end.x; i++)
        {
            uint32_t *pixel = frame_at(frame, (Vec2D){start.x + i, k + start.y});
            *pixel = color;
        }
    }
}

/**
 * @brief Draws a line on the screen in the y direction
 *
 * @param frame The frame
 * @param start The start position
 * @param end The end position
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_line_y(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
    for (int k = 0; k < width; k++)
    {
        for (int i = 0; i < start.y - end.y; i++)
        {
            uint32_t *pixel = frame_at(frame, (Vec2D){k + start.x, start.y + i});
            *pixel = color;
        }
    }
}

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
void _draw_line(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
    for (int k = 0; k < width; k++)
    {
        for (int i = 0; i < start.x - end.x; i++)
        {
            for (int j = 0; j < start.y - end.y; j++)
            {
                uint32_t *pixel = frame_at(frame, (Vec2D){k + start.x + i, k + start.y + j});
                *pixel = color;
            }
        }
    }
}

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
void draw_line(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
    if (start.y == end.y)
        draw_line_x(frame, start, end, color, width);
    else if (start.x == end.x)
        draw_line_y(frame, start, end, color, width);
    else
        _draw_line(frame, start, end, color, width);
}

#endif // GRAPHICS_LINE