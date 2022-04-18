//
// Created by chappie on 30.03.2022.
//

#include "Size.h"

Size::Size(unsigned long _width, unsigned long _height) : width(_width), height(_height) {}

unsigned long Size::getWidth() const {
    return this->width;
}

unsigned long Size::getHeight() const {
    return this->height;
}

void Size::setWidth(int _width) {
    this->width = _width;
}

void Size::setHeight(int _height) {
    this->height = _height;
}

Size::Size(const Size &other) {
    this->width = other.width;
    this->height = other.height;
}

Size &Size::operator=(const Size &other) {
    this->width = other.width;
    this->height = other.height;
    return *this;
}

