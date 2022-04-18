//
// Created by chappie on 31.03.2022.
//

#include "GammaCorrectionProcessor.h"
#include <cmath>

GammaCorrectionProcessor::GammaCorrectionProcessor(float _gamma) : gamma(_gamma) {}

GammaCorrectionProcessor::GammaCorrectionProcessor() : gamma(1) {}

void GammaCorrectionProcessor::process(const Image &src, Image &dst) {
    //note: same thing as the BrightnessProcessor
    dst.release();
    dst = src;
    for (int i = 0; i < src.height(); i++)
        for (int j = 0; j < src.width(); j++)
            dst.at(i, j) = UCHAR_CLAMP(pow(int(src.atConst(i, j)), this->gamma));
    //dst.refresh(); //this is commented to improve the demo
}