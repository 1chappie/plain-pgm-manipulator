//
// Created by chappie on 31.03.2022.
//
#ifndef LABORATORY4_1CHAPPIE_BRIGHTNESSCONTRASTPROCESSOR_H
#define LABORATORY4_1CHAPPIE_BRIGHTNESSCONTRASTPROCESSOR_H

#include "ImageProcessor.h"

class BrightnessContrastProcessor : public ImageProcessor {
public:
    friend class ImageProcessingTests;
    /**
     * Creates a BrightnessContrastProcessor instance, which will be able to process images with the given values.
     * Follows the formula F(x , y) = gain * I(x, y) + bias;
     * where I(x, y) is the original image and F(x, y) is the new image.
     * @param _gain
     * @param _bias
     */
    BrightnessContrastProcessor(float _gain, float _bias);

    BrightnessContrastProcessor();

    /**
     * Processes the given image and returns the new image in the 2nd parameter.
     * @param[in] src - image to be processed
     * @param[out] dst - save destination
     */
    void process(const Image &src, Image &dst) override;

private:
    float gain;
    float bias;
};


#endif //LABORATORY4_1CHAPPIE_BRIGHTNESSCONTRASTPROCESSOR_H
