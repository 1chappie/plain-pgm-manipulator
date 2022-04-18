//
// Created by chappie on 30.03.2022.
//

#ifndef LABORATORY4_1CHAPPIE_RECTANGLE_H
#define LABORATORY4_1CHAPPIE_RECTANGLE_H

#include "Point.h"
#include "Size.h"
#include "Vector2D.h"

class Rectangle {
private:
    unsigned long width;
    unsigned long height;
    unsigned long cornerX;
    unsigned long cornerY;
public:

    friend class Image;

    /**
     * Constructor
     * @param width - width of the rectangle
     * @param height - height of the rectangle
     * @param cornerX - x coordinate of the top left corner
     * @param cornerY - y coordinate of the top left corner
     */
    Rectangle(unsigned long width, unsigned long height, unsigned long cornerX, unsigned long cornerY);

    Rectangle(const Rectangle &rectangle);

    Rectangle &operator=(const Rectangle &rectangle);

    /**
     * Translates the rectangle by the given vector
     * @param vector - 2D vector to translate the rectangle by
     * @return translated rectangle
     */
    Rectangle &operator+(Vector2D &vector);

    /**
     * Translates the rectangle by the given vector
     * @param vector - 2D vector to translate the rectangle by
     * @return translated rectangle
     */
    Rectangle &operator-(Vector2D &vector);

    /**
     * Compute the intersection between two rectangles.
     * @param rectangle - rectangle to compute the intersection with
     * @return rectangle object that respects the size of the intersection
     */
    Rectangle &operator&(const Rectangle &rectangle);

    /**
     * Compute the union between two rectangles.
     * Returns the smalles possible rectangle that contains both rectangles.
     * @param rectangle - rectangle to compute the union with
     * @return rectangle object that respects the size of the union
     */
    Rectangle &operator|(const Rectangle &rectangle);

    /**
     * Constructor
     * @param size - size of the rectangle
     * @param corner - top left corner of the rectangle
     */
    Rectangle(const Size &size, const Point &corner);

    /**
     * Constructor
     * @param topLeft - top left corner of the rectangle
     * @param bottomRight - bottom right corner of the rectangle
     */
    Rectangle(const Point &topLeft, const Point &bottomRight);

    unsigned long getWidth() const;

    unsigned long getHeight() const;

    unsigned long getCornerX() const;

    unsigned long getCornerY() const;

    /**
     * Returns a Size object that represents the width * height of the rectangle
     * @return Size
     */
    Size getSize() const;

    /**
     * Returns a Point object that represents the top left corner of the rectangle
     * @return Point
     */
    Point getCorner() const;

    /**
     * Returns a Point object that represents the top left corner of the rectangle
     * @return Point
     */
    Point getTopLeft() const;

    /**
     * Returns a Point object that represents the bottom right corner of the rectangle
     * @returns Point
     */
    Point getBottomRight() const;

    void setWidth(unsigned long width);

    void setHeight(unsigned long height);

    void setCornerX(unsigned long cornerX);

    void setCornerY(unsigned long cornerY);

    void setSize(const Size &size);

    void setCorner(const Point &corner);
};


#endif //LABORATORY4_1CHAPPIE_RECTANGLE_H
