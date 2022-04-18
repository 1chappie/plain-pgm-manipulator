//
// Created by chappie on 02.04.2022.
//

#ifndef LABORATORY4_1CHAPPIE_BRUSH_H
#define LABORATORY4_1CHAPPIE_BRUSH_H

#include "Image.h"

class Brush {
public:
    /**
     * Creates a circle within the given parameters.
     * @param img - the image to draw on
     * @param center - the center of the circle, given as a Point
     * @param radius - the radius of the circle
     * @param color - the color of the circle
     * @param repl - whether to replace the pixels or not. If false, the pixels will be added. Defaults to true.
     * @return true if the circle was drawn successfully, false otherwise
     */
    static bool drawCircle(Image &img, Point center, int radius, unsigned char color, bool repl = true);

    /**
     * Creates a line within the given parameters by using Bresenham's algorithm.
     * @param img - the image to draw on
     * @param start - the start point of the line, given as a Point
     * @param end - the end point of the line, given as a Point
     * @param color - the color of the line
     * @param repl - whether to replace the pixels or not. If false, the pixels will be added. Defaults to true.
     * @return true if the line was drawn successfully, false otherwise
     */
    static bool drawLine(Image &img, Point start, Point end, unsigned char color, bool repl = true);

    /**
     * Creates a rectangle within the given parameters.
     * @overloads drawRectangle(Image &img, Point tl, Point br, unsigned char color, bool repl = true)
     * @param img - the image to draw on
     * @param r - the rectangle to draw, given as a Rectangle
     * @param color - the color of the rectangle
     * @param repl - whether to replace the pixels or not. If false, the pixels will be added. Defaults to true.
     * @return true if the rectangle was drawn successfully, false otherwise
     */
    static bool drawRectangle(Image &img, Rectangle r, unsigned char color, bool repl = true);

    /**
     * Creates a rectangle within the given parameters.
     * @param img - the image to draw on
     * @param tl - the top left corner of the rectangle, given as a Point
     * @param br - the bottom right corner of the rectangle, given as a Point
     * @param color - the color of the rectangle
     * @param repl - whether to replace the pixels or not. If false, the pixels will be added. Defaults to true.
     * @return true if the rectangle was drawn successfully, false otherwise
     */
    static bool drawRectangle(Image &img, Point tl, Point br, unsigned char color, bool repl = true);

private:
    static void plotLineLow(Image &img, int x0, int y0, int x1, int y1, unsigned char color, bool repl);

    static void plotLineHigh(Image &img, int x0, int y0, int x1, int y1, unsigned char color, bool repl);

};


#endif //LABORATORY4_1CHAPPIE_BRUSH_H
