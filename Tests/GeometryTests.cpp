//
// Created by chappie on 05.04.2022.
//

#include <sstream>
#include "GeometryTests.h"

void GeometryTests::execute() {
    std::cout << CYAN "Executing Geometry Tests..." NC << std::endl;
    GeometryTests::test_point();
    GeometryTests::test_rectangle();
    GeometryTests::test_size();
    GeometryTests::test_2Dvector();
    std::cout << GREEN "Passed!" NC << std::endl;
}

void GeometryTests::test_point() {
    Point p0;
    Point p(2, 5);
    assert(p0.getX() == 0);
    assert(p0.getY() == 0);
    assert(p.getX() == 2);
    assert(p.getY() == 5);
    p0.setX(3);
    p0.setY(7);
    assert(p0.getX() == 3);
    assert(p0.getY() == 7);
    Point p2 = p;
    assert(p2.getX() == p.getX());
    assert(p2.getY() == p.getY());
    p0 = p;
    assert(p0.getX() == p.getX());

    Point a(10, 20);
    std::ostringstream sstr;
    std::string s = "(10,20)";
    sstr << a;
    assert(sstr.str() == s);

    std::istringstream sstr2("2 5");
    std::string s1 = "";
    sstr2 >> a;

    assert(a.getX() == 2);
    assert(a.getY() == 5);
}

void GeometryTests::test_rectangle() {
    Rectangle r(5, 2, 1, 1);
    Rectangle r2(10, 3, 5, 5);

    assert(r.getHeight() == 2);
    assert(r.getWidth() == 5);
    assert(r.getCornerX() == 1);
    assert(r.getCornerY() == 1);
    r.setCorner(Point(2, 2));
    assert(r.getCornerX() == 2);
    assert(r.getCornerY() == 2);
    r.setSize(Size(4, 6));
    assert(r.getHeight() == 6);
    assert(r.getWidth() == 4);
    r.setCornerX(3);
    r.setCornerY(4);
    assert(r.getCornerX() == 3);
    assert(r.getCornerY() == 4);
    r.setHeight(5);
    r.setWidth(7);
    assert(r.getHeight() == 5);
    assert(r.getWidth() == 7);

    Rectangle r3(0, 0, 0, 0), r4(0, 0, 0, 0);
    Vector2D v(4, 5);
    Vector2D v1(2, 2);

    r3 = r + v;
    assert(r3.getCornerX() == 7);
    assert(r3.getCornerY() == 9);

    r4 = r3 - v1;
    assert(r4.getCornerX() == 5);
    assert(r4.getCornerY() == 7);

    Rectangle rect1(5, 5, 1, 1);
    Rectangle rect2(5, 5, 2, 2);
    Rectangle rect3(0, 0, 0, 0);

    rect3 = rect1 & rect2;

    assert(rect3.getCornerX() == 2);
    assert(rect3.getCornerY() == 2);
    assert(rect3.getHeight() == 4);
    assert(rect3.getWidth() == 4);

    try {
        Rectangle rect4(1, 2, 100, 100);
        rect4 = rect4 & rect3;
        assert(false);
    }
    catch (...) {
        assert(true);
    }

    rect1 = Rectangle(5, 5, 1, 1);
    rect2 = Rectangle(2, 5, 6, 6);
    rect3 = rect1 | rect2;

    assert(rect3.getWidth() == 7);

    assert(rect3.getSize().getWidth() == 7);

    Rectangle SPrect(Size(5, 5), Point(1, 1));
    assert(SPrect.getCornerX() == 1);
    assert(SPrect.getWidth() == 5);

    Point topLeft_corner(4, 3);
    Point bottomRight_corner(5, 8);

    Rectangle rect(topLeft_corner, bottomRight_corner);

    assert(rect.getTopLeft().getX() == 4);
    assert(rect.getTopLeft().getY() == 3);

    try {
        Rectangle rect1(bottomRight_corner, topLeft_corner);
        assert(false);
    }
    catch (...) {
        assert(true);
    }

    assert(rect.getCorner().getX() == 4);
}

void GeometryTests::test_size() {
    Size s(5, 2), s2(0,0);
    assert(s.getWidth() == 5);
    assert(s.getHeight() == 2);
    s.setWidth(3);
    s.setHeight(4);
    assert(s.getWidth() == 3);
    assert(s.getHeight() == 4);
    s.setWidth(5);
    s.setHeight(2);
    assert(s.getWidth() == 5);
    assert(s.getHeight() == 2);
    s2 = s;
    assert(s2.getWidth() == 5);
    Size s3 = s;
    assert(s3.getWidth() == 5);
}

void GeometryTests::test_2Dvector() {
    Vector2D v(1, 2);
    Vector2D v2;
    assert(v.getX() == 1);
    v2.setX(3);
    v2.setY(200);
    assert(v2.getX() == 3);
    v2 = v;
    assert(v2.getX() == 1);
}
