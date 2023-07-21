#ifndef WINDOW_FRAME_H
#define WINDOW_FRAME_H

#include <stdint.h>
#include <windows.h>
#include "../common/vec2d.h"

/**
 * @brief The frame
 * 
 * @param width The width of the frame
 * @param height The height of the frame
 * @param pixels The pixels of the frame
 * @param bitmap_info The bitmap info of the frame
 * @param device_context The device context of the frame
 * 
 */
typedef struct Frame
{
    int width;
    int height;
    uint32_t *pixels;

    BITMAPINFO *bitmap_info;
    HDC device_context;
} Frame;

#endif // WINDOW_FRAME_H