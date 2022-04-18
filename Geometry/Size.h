//
// Created by chappie on 30.03.2022.
//

#ifndef LABORATORY4_1CHAPPIE_SIZE_H
#define LABORATORY4_1CHAPPIE_SIZE_H


class Size {
private:
    unsigned long width;
    unsigned long height;
public:

    friend class Image;

    /**
     * Constructor
     * @param width - width of the Size object
     * @param height - height of the Size object
     */
    Size(unsigned long width, unsigned long height);

    Size(const Size &);

    Size &operator=(const Size &);

    unsigned long getWidth() const;

    unsigned long getHeight() const;

    void setWidth(int width);

    void setHeight(int height);
};

#endif //LABORATORY4_1CHAPPIE_SIZE_H
