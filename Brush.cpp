//
// Created by chappie on 02.04.2022.
//

#include "Brush.h"
#include <cmath>
#include<iostream>

bool Brush::drawCircle(Image &img, Point center, int radius, unsigned char color, bool repl) {
    unsigned long centerY = center.getY();
    unsigned long centerX = center.getX();
    unsigned int height = img.height();
    unsigned int width = img.width();
    if (radius == 0)
        return false;
    if (centerX + radius >= width || centerY + radius >= height ||
        (long) (centerX - radius) < 0 || (long) (centerY - radius) < 0)
        return false;
    //a for loop for each quadrant
    for (int y = 0; y < centerY; y++)
        for (int x = 0; x < centerX; x++)
            //using the standard form for the equation of a circle to find whether
            //a point is inside the given radius or not
            //(https://saylordotorg.github.io/text_intermediate-algebra/s11-02-circles.html)
            if ((pow((centerX - x), 2)) + (pow((centerY - y), 2)) <= pow(radius, 2))
                repl ? img.at(y, x) = color : img.at(y, x) += color;
    for (int y = 0; y < centerY; y++)
        for (int x = centerX; x < width; x++)
            if ((pow((x - centerX), 2)) + (pow((centerY - y), 2)) <= pow(radius, 2))
                repl ? img.at(y, x) = color : img.at(y, x) += color;
    for (int y = centerY; y < height; y++)
        for (int x = centerX; x < width; x++)
            if ((pow((x - centerX), 2)) + (pow((y - centerY), 2)) <= pow(radius, 2))
                repl ? img.at(y, x) = color : img.at(y, x) += color;
    for (int y = centerY; y <= height; y++)
        for (int x = 0; x < centerX; x++)
            if ((pow((centerX - x), 2)) + (pow((y - centerY), 2)) <= pow(radius, 2))
                repl ? img.at(y, x) = color : img.at(y, x) += color;
    img.refresh();
    return true;
}

bool Brush::drawLine(Image &img, Point p1, Point p2, unsigned char color, bool repl) {
//    Using https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    int x0 = p1.getX();
    int y0 = p1.getY();
    int x1 = p2.getX();
    int y1 = p2.getY();
    if (x0 == x1 && y0 == y1) //checking if coordinates are valid
        return false;
    if (x0 > img.width() || x1 > img.width() || y0 > img.height() || y1 > img.height())
        return false;

    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1)
            Brush::plotLineLow(img, x1, y1, x0, y0, color, repl);
        else
            Brush::plotLineLow(img, x0, y0, x1, y1, color, repl);
    } else {
        if (y0 > y1)
            Brush::plotLineHigh(img, x1, y1, x0, y0, color, repl);
        else
            Brush::plotLineHigh(img, x0, y0, x1, y1, color, repl);
    }
    img.refresh();
    return true;
}

void Brush::plotLineLow(Image &img, int x0, int y0, int x1, int y1, unsigned char color, bool repl) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    int D = 2 * dy - dx;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        repl ? img.at(y, x) = color : img.at(y, x) += color;
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        } else
            D = D + 2 * dy;
    }
}

void Brush::plotLineHigh(Image &img, int x0, int y0, int x1, int y1, unsigned char color, bool repl) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    int D = 2 * dx - dy;
    int x = x0;
    for (int y = y0; y <= y1; y++) {
        repl ? img.at(y, x) = color : img.at(y, x) += color;
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        } else
            D = D + 2 * dx;
    }
}

bool Brush::drawRectangle(Image &img, Point tl, Point br, unsigned char color, bool repl) {
    if (tl.getX() > img.width() || tl.getY() > img.height() || br.getX() > img.width() || br.getY() > img.height())
        return false;
    if (tl.getX() > br.getX() || tl.getY() > br.getY())
        return false;
    for (int x = tl.getX(); x <= br.getX(); x++)
        for (int y = tl.getY(); y <= br.getY(); y++)
            repl ? img.at(y, x) = color : img.at(y, x) += color;
    img.refresh();
    return true;
}

bool Brush::drawRectangle(Image &img, Rectangle r, unsigned char color, bool repl) {
    return Brush::drawRectangle(img, r.getTopLeft(), r.getBottomRight(), color, repl);
}

