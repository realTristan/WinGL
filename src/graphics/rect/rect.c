#ifndef GRAPHICS_RECT_C
#define GRAPHICS_RECT_C

#include "../../common/vec2d.h" //for Vec2D type
#include "../../window/frame.h" //for frame type
#include "../line/positioned.h" //for the draw_positioned_line function
#include <stdint.h> //for uint32_t type
#include "rect.h" //function declaration for draw_rectangle

/**
 * @brief draws a rectangle on the screen
 *
 * @param frame the frame where to draw the rectangle
 * @param top_left the top left corner of the rectangle
 * @param size the size of the rectangle (width x height)
 * @param color the color of the rectangle
 * @param thickness the thickness of the rectangle's border
 * @return void
 */
void draw_rectangle(Frame *frame, Vec2D top_left, Vec2D size, uint32_t color, int thickness) {
    //draw top horizontal line
    draw_positioned_line(frame, top_left, (Vec2D){top_left.x + size.x, top_left.y}, color, thickness);

    //draw bottom horizontal line
    draw_positioned_line(frame, (Vec2D){top_left.x, top_left.y + size.y}, (Vec2D){top_left.x + size.x, top_left.y + size.y}, color, thickness);

    //draw left vertical line
    draw_positioned_line(frame, top_left, (Vec2D){top_left.x, top_left.y + size.y}, color, thickness);

    //draw right vertical line
    draw_positioned_line(frame, (Vec2D){top_left.x + size.x, top_left.y}, (Vec2D){top_left.x + size.x, top_left.y + size.y}, color, thickness);
}

#endif // GRAPHICS_RECT_C
