//
// Created by chappie on 31.03.2022.
//
#ifndef LABORATORY4_1CHAPPIE_POINT_H
#define LABORATORY4_1CHAPPIE_POINT_H

#include <iosfwd>

class Point {
private:
    unsigned long x; //spec says int?
    unsigned long y;
public:
    friend class Image;

    friend class Brush;

    /**
     * Constructor
     * @param x - x coordinate
     * @param y - y coordinate
     */
    Point(unsigned long x, unsigned long y);

    Point();

    Point(const Point &point);

    Point &operator=(const Point &point);

    /**
     * Creates a string representation of the point
     * @param out - output stream
     * @return output stream
     */
    friend std::ostream &operator<<(std::ostream &out, const Point &);

    friend std::istream &operator>>(std::istream &in, Point &);

    unsigned long getX() const;

    unsigned long getY() const;

    void setX(unsigned long x);

    void setY(unsigned long y);
};


#endif //LABORATORY4_1CHAPPIE_POINT_H
