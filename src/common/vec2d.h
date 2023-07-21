#ifndef WINDOW_VEC2D_H
#define WINDOW_VEC2D_H

/**
 * @brief A 2D vector
 * 
 * @param x The x value
 * @param y The y value
 * 
 */
typedef struct Vec2D
{
    int x;
    int y;
} Vec2D;

/**
 * @brief Substract two vectors
 * 
 */
inline Vec2D vec2d_sub(Vec2D a, Vec2D b)
{
    return (Vec2D){a.x - b.x, a.y - b.y};
}

/**
 * @brief Add two vectors
 * 
 */
inline Vec2D vec2d_add(Vec2D a, Vec2D b)
{
    return (Vec2D){a.x + b.x, a.y + b.y};
}

/**
 * @brief Multiply two vectors
 * 
 */
inline Vec2D vec2d_mul(Vec2D a, Vec2D b)
{
    return (Vec2D){a.x * b.x, a.y * b.y};
}

#endif // WINDOW_VEC2D_H