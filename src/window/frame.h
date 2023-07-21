#ifndef FRAME_H
#define FRAME_H

#include <stdint.h>
#include <windows.h>

typedef struct Frame
{
    int width;
    int height;
    uint32_t *pixels;

    BITMAPINFO *bitmap_info;
    HBITMAP bitmap;
    HDC device_context;
} Frame;

static Frame *frame = {0};

#endif // FRAME_H