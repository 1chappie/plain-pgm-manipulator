//
// Created by chappie on 31.03.2022.
//

#include "BrightnessContrastProcessor.h"
#include <iostream>

BrightnessContrastProcessor::BrightnessContrastProcessor(float _gain, float _bias) : gain(_gain), bias(_bias) {}

BrightnessContrastProcessor::BrightnessContrastProcessor() : BrightnessContrastProcessor(1.0, 0) {}

void BrightnessContrastProcessor::process(const Image &src, Image &dst) {
    // note: values that are too high will just destroy the image by clamping everything to 255
    // all processing should be normalized somehow
    // but this is a lab not an internship
    dst.release();
    dst = Image(src.size());
    for (int i = 0; i < src.height(); i++)
        for (int j = 0; j < src.width(); j++)
            dst.at(i, j) = UCHAR_CLAMP((this->gain * int(src.atConst(i, j))) + this->bias);
    dst.refresh();
}

