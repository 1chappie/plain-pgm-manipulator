//
// Created by chappie on 31.03.2022.
//

#ifndef LABORATORY4_1CHAPPIE_CONVOLUTIONPROCESSOR_H
#define LABORATORY4_1CHAPPIE_CONVOLUTIONPROCESSOR_H

#include "ImageProcessor.h"
#include <vector>

using std::vector;

enum class ConvolutionType {
    IDENTITY,
    MEAN_BLUR,
    GAUSSIAN_BLUR,
    HORIZONTAL_SOBEL,
    VERTICAL_SOBEL
};

class ConvolutionProcessor : public ImageProcessor {
public:
    friend class ImageProcessingTests;
    /**
     * Handles the image convolution by applying a preset kernel to the image.
     * More information on the convolutional filter can be found here: https://en.wikipedia.org/wiki/Kernel_(image_processing).
     * @overloads ImageProcessor::ConvolutionProcessor(ConvolutionType _type, usigned char (*downScaler)(long, int))
     * @param _type - the type of the convolution, must be one of the enum values of ConvolutionType
     */
    ConvolutionProcessor(ConvolutionType _type); //uses preset kernel and downscale255

    /**
     * Handles the image convolution by applying a preset kernel to the image.
     * More information on the convolutional filter can be found here: https://en.wikipedia.org/wiki/Kernel_(image_processing).
     * A downScaler function of type unsigned char (*)(long, int) can be passed to the constructor to change the way the image is downscaled.
     * @overloads ConvolutionProcessor(const vector<vector<int>> &kernelPattern, int kernelWidth,
                         unsigned char (*downScaler)(long, int))
     * @param _type - the type of the convolution, must be one of the enum values of ConvolutionType
     * @param downScaler - function that downscales the result of the convolution
     */
    ConvolutionProcessor(ConvolutionType _type,
                         unsigned char (*downScaler)(long, int)); //uses preset kernel and CUSTOM downscaler

    /**
     * Handles the image convolution by applying a kernelPattern of size kernelSize to the image.
     * More information on the convolutional filter can be found here: https://en.wikipedia.org/wiki/Kernel_(image_processing).
     * A downScaler function of type unsigned char (*)(long, int) can be passed to the constructor to change the way the image is downscaled.
     * IMPORTANT: The kernelPattern must be symmetric and have an odd size.
     * @param kernelPattern - 2D vector containing the kernelPattern
     * @param kernelWidth - width of the kernelPattern
     * @param downScaler - function that downscales the result of the convolution
     * @see downScale255(long, int)
     */
    ConvolutionProcessor(const vector<vector<int>> &kernelPattern, int kernelWidth,
                         unsigned char (*downScaler)(long, int)); //uses CUSTOM kernel and CUSTOM downscaler

    /**
     * Processes the given image and returns the new image in the 2nd parameter.
     * @param[in] src - image to be processed
     * @param[out] dst - save destination
     */
    void process(const Image &src, Image &dst) override;

    /**
     * Uses cross multiplication of a peak, a reference value and a current element to
     * appropriately downscale the current element in relation to the reference value.
     * @param peak - the peak value of the new image before downscaling
     * @param current - the value that needs to be downscaled
     * @return the downscaled value, in accordance to the downscaling of the peak to the reference (255)
     */
    friend unsigned char downScale255(long peak, int current);

private:
    vector<vector<int>> kernel;
    int kernelWidth;

    unsigned char (*downScaler)(long, int);
};


#endif //LABORATORY4_1CHAPPIE_CONVOLUTIONPROCESSOR_H
