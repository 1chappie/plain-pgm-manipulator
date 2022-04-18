//
// Created by chappie on 01.04.2022.
//

#include "Vector2D.h"

Vector2D::Vector2D(double _x, double _y) : x(_x), y(_y) {}

Vector2D::Vector2D() : x(0), y(0) {}

double Vector2D::getX() const {
    return this->x;
}

double Vector2D::getY() const {
    return this->y;
}

void Vector2D::setX(double _x) {
    this->x = _x;
}

void Vector2D::setY(double _y) {
    this->y = _y;
}

Vector2D &Vector2D::operator=(const Vector2D &other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}
