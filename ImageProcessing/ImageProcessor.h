//
// Created by chappie on 31.03.2022.
//

#ifndef LABORATORY4_1CHAPPIE_IMAGEPROCESSOR_H
#define LABORATORY4_1CHAPPIE_IMAGEPROCESSOR_H

#include "../Image.h"

class ImageProcessor {
public:

    virtual void process(const Image &, Image &) = 0;
};


#endif //LABORATORY4_1CHAPPIE_IMAGEPROCESSOR_H
