//
// Created by chappie on 01.04.2022.
//

#ifndef LABORATORY4_1CHAPPIE_VECTOR2D_H
#define LABORATORY4_1CHAPPIE_VECTOR2D_H


class Vector2D {
private:
    double x;
    double y;
public:
    /**
     * Constructor
     * @params x, y - components of the vector
     */
    Vector2D(double x, double y);

    Vector2D();

    double getX() const;

    double getY() const;

    void setX(double x);

    void setY(double y);

    Vector2D &operator=(const Vector2D &other);

};


#endif //LABORATORY4_1CHAPPIE_VECTOR2D_H
