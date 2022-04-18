//
// Created by chappie on 05.04.2022.
//

#include "BrushTests.h"

void BrushTests::execute() {
    std::cout << CYAN "Executing Drawing Tests..." NC << std::endl;
    BrushTests::test_circle();
    BrushTests::test_line();
    BrushTests::test_rectangle();
    std::cout << GREEN "Passed!" NC << std::endl;
}

void BrushTests::test_circle() {
    Image image = Image::generateFilled(100, 100, 2);
    Brush::drawCircle(image, Point(50,50), 10, 3, true);
    assert(image.at(52,57) == 3);
}

void BrushTests::test_line() {
    Image image = Image::generateFilled(100, 100, 2);
    Brush::drawLine(image, Point(50,50), Point(50,60), 3, true);
    Brush::drawLine(image, Point(50,50), Point(60,50), 3, true);
    assert(image.at(50,50) == 3);
}

void BrushTests::test_rectangle() {
    Image image = Image::generateFilled(100, 100, 2);
    Brush::drawRectangle(image, Point(10,10), Point(60,60), 5, false);
    assert(image.at(50,50) == 7);
    Brush::drawRectangle(image, Rectangle(20,20,2,2), 20, true);

}

