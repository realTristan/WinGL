#ifndef GRAPHICS_LINE_POSITIONED_C
#define GRAPHICS_LINE_POSITIONED_C

#include "../../common/vec2d.h"
#include "../../window/window.h"
#include <stdint.h>
#include <math.h>
#include <stdio.h>

/**
 * @brief Draws a line on the screen horizontal
 *
 * @param frame The frame
 * @param start The start position
 * @param end The end position
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_positioned_line_horizontal(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
    // Calculate the y length (absolute value)
    int x_length = abs(end.x - start.x);
    
    for (int w = 0; w < width; w++)
    {
        // Draw the pixels
        for (int i = 0; i < x_length; i++)
        {
            uint32_t *pixel = frame_at(frame, (Vec2D){start.x + i, start.y + w});
            *pixel = color;
        }
    }
}

/**
 * @brief Draws a line on the screen vertical
 *
 * @param frame The frame
 * @param start The start position
 * @param end The end position
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_positioned_line_vertical(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
    // Calculate the x length (absolute value)
    int y_length = abs(end.y - start.y);

    for (int w = 0; w < width; w++)
    {
        // Draw the pixels
        for (int i = 0; i < y_length; i++)
        {
            uint32_t *pixel = frame_at(frame, (Vec2D){start.x + w, start.y + i});
            *pixel = color;
        }
    }
}

/**
 * @brief Draws a line on the screen diagonal
 *
 * @param frame The frame
 * @param start The start position
 * @param end The end position
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_positioned_line_diagonal(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
    // Calculate the slope rounded up
    float slope = (float)(end.y - start.y) / (float)(end.x - start.x);

    // Calculate the x length (absolute value)
    int x_length = abs(end.x - start.x);

    for (int w = 0; w < width; w++)
    {
        // Keep track of the y position
        float y_pos = start.y + w * slope;

        // Draw the pixels
        for (int i = 0; i < x_length; i++)
        {
            // Draw y pixels based on the slope
            for (int j = 0; j < slope; j++)
            {
                uint32_t *pixel = frame_at(frame, (Vec2D){start.x + i, y_pos + j});
                *pixel = color;
            }

            // Increment the y position
            y_pos += slope;
        }
    }
}

/**
 * @brief Draws a line on the screen whether it be horizontal, vertical, or diagonal
 *
 * @param frame The frame
 * @param start The start position
 * @param end The end position
 * @param color The color of the line
 * @param width The width of the line
 * @return void
 */
void draw_positioned_line(Frame *frame, Vec2D start, Vec2D end, uint32_t color, int width)
{
    if (start.x == end.x)
        draw_positioned_line_vertical(frame, start, end, color, width);
    else if (start.y == end.y)
        draw_positioned_line_horizontal(frame, start, end, color, width);
    else
        draw_positioned_line_diagonal(frame, start, end, color, width);
}

#endif // GRAPHICS_LINE_POSITIONED_C