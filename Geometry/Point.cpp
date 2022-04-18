//
// Created by chappie on 31.03.2022.
//

#include <sstream>
#include "Point.h"

Point::Point(unsigned long x, unsigned long y) : x(x), y(y) {}

Point::Point() : x(0), y(0) {}

Point::Point(const Point &point) : x(point.x), y(point.y) {}

Point &Point::operator=(const Point &point) {
    this->x = point.x;
    this->y = point.y;
    return *this;
}

unsigned long Point::getX() const {
    return this->x;
}

unsigned long Point::getY() const {
    return this->y;
}

void Point::setX(unsigned long x) {
    this->x = x;
}

void Point::setY(unsigned long y) {
    this->y = y;
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    std::ostringstream ss;
    ss << "(" << point.getX() << "," << point.getY() << ")";
    out << ss.str();
    return out;
}

std::istream &operator>>(std::istream &in, Point &point) {
    //TODO ish - this wont work if it's given as "(x,y)"
    in >> point.x;
    in >> point.y;
    return in;
}



