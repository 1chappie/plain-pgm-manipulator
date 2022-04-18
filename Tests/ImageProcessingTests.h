//
// Created by chappie on 05.04.2022.
//

#ifndef LABORATORY4_1CHAPPIE_IMAGEPROCESSINGTESTS_H
#define LABORATORY4_1CHAPPIE_IMAGEPROCESSINGTESTS_H

#include "../Tests.h"
#include "../ImageProcessing.h"

class ImageProcessingTests {
public:
    static void execute();
private:
    static void test_brightness_and_contrast();
    static void test_convolution();
    static void test_gamma_correction();
};


#endif //LABORATORY4_1CHAPPIE_IMAGEPROCESSINGTESTS_H
