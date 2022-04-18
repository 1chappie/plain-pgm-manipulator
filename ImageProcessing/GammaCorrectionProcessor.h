//
// Created by chappie on 31.03.2022.
//

#ifndef LABORATORY4_1CHAPPIE_GAMMACORRECTIONPROCESSOR_H
#define LABORATORY4_1CHAPPIE_GAMMACORRECTIONPROCESSOR_H

#include "ImageProcessor.h"

class GammaCorrectionProcessor : public ImageProcessor {
public:
    friend class ImageProcessingTests;
    /**
     * Creates a GammaCorrectionProcessor instance, which will be able to process images with the given values.
     * Follows the formula F(x , y) =  I(x, y)^ gamma;
     * where I(x, y) is the original image and F(x, y) is the new image.
     * @param gamma - exponentially increase the brightness of the image by the factor
     */
    GammaCorrectionProcessor(float gamma);

    GammaCorrectionProcessor();

    /**
     * Processes the given image and returns the new image in the 2nd parameter.
     * @param[in] src - image to be processed
     * @param[out] dst - save destination
     */
    void process(const Image &src, Image &dst) override;

private:
    float gamma;
};


#endif //LABORATORY4_1CHAPPIE_GAMMACORRECTIONPROCESSOR_H
