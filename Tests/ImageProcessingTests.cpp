//
// Created by chappie on 05.04.2022.
//

#include "ImageProcessingTests.h"
#include "../ImageProcessing/ConvolutionProcessor.h"

void ImageProcessingTests::execute() {
    std::cout << CYAN "Executing Image Processing Tests..." NC << std::endl;
    ImageProcessingTests::test_brightness_and_contrast();
    ImageProcessingTests::test_convolution();
    ImageProcessingTests::test_gamma_correction();
    std::cout << GREEN "Passed!" NC << std::endl;
}

void ImageProcessingTests::test_brightness_and_contrast() {
    BrightnessContrastProcessor processorempty;
    assert(processorempty.gain == 1);
    assert(processorempty.bias == 0);

    BrightnessContrastProcessor processor(2, 4);
    assert(processor.gain == 2);
    assert(processor.bias == 4);

    Image image1 = Image::zeros(1, 1), image2;
    processor.process(image1, image2);

    assert(image1.at(0, 0) == 0);
}

void ImageProcessingTests::test_gamma_correction() {
    GammaCorrectionProcessor emptyprocessor;
    assert(emptyprocessor.gamma == 1);

    GammaCorrectionProcessor processor(2);
    assert(processor.gamma == 2);

    Image image1 = Image::generateFilled(5, 5, 2), image2;
    processor.process(image1, image2);

    assert(image2.at(0, 1) == 4);
}

void ImageProcessingTests::test_convolution() {
    ConvolutionProcessor procesor(ConvolutionType::GAUSSIAN_BLUR);
    //i really don't have the time to test this properly
    //TODO
    Image src = Image::generateFilled(5, 5, 2), dst;
    procesor.process(src, dst);
    assert(dst.at(1, 1) == 32);
    ConvolutionProcessor procesor2(ConvolutionType::IDENTITY);
    procesor2.process(src, dst);
    assert(dst.at(1, 1) == 2);
}
