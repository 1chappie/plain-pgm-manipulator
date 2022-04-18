//
// Created by chappie on 26.03.2022.
//
#include "Image.h"
#include "Geometry.h"
#include "ImageProcessing.h"
#include "Brush.h"
#include "Tests.h"
#include <iostream>

void demo() {
    Image original, temp1, temp2;
    original.load("../BonusProblem2/Demo/balo.pgm");

    Image roi;
    original.getROI(roi, Rectangle(200, 200, 50, 50));
    roi.save("../BonusProblem2/Demo/1roi.pgm");

    Image processed;
    BrightnessContrastProcessor bcProcessor(1.6, 2);
    bcProcessor.process(original, processed);
    processed.save("../BonusProblem2/Demo/2brightness_contrast.pgm");

    GammaCorrectionProcessor gammaProcessor(0.8);
    gammaProcessor.process(original, processed);
    processed.save("../BonusProblem2/Demo/3gamma.pgm");

    ConvolutionProcessor meanBlurProcessor(ConvolutionType::MEAN_BLUR);
    meanBlurProcessor.process(original, temp1);
    meanBlurProcessor.process(temp1, temp2);
    meanBlurProcessor.process(temp2, processed);
    processed.save("../BonusProblem2/Demo/4mean_blur.pgm");

    ConvolutionProcessor gaussianBlurProcessor(ConvolutionType::GAUSSIAN_BLUR);
    gaussianBlurProcessor.process(original, temp1);
    gaussianBlurProcessor.process(temp1, temp2);
    gaussianBlurProcessor.process(temp2, processed);
    processed.save("../BonusProblem2/Demo/5gaussian_blur.pgm");

    ConvolutionProcessor hsobelProcessor(ConvolutionType::HORIZONTAL_SOBEL);
    hsobelProcessor.process(original, processed);
    processed.save("../BonusProblem2/Demo/6hsobelProcessor.pgm");

    ConvolutionProcessor vsobelProcessor(ConvolutionType::VERTICAL_SOBEL);
    vsobelProcessor.process(original, processed);
    processed.save("../BonusProblem2/Demo/7vsobelProcessor.pgm");

    temp1 = original;
    Brush::drawCircle(temp1, Point(100, 100), 80, 0, true);
    Brush::drawCircle(temp1, Point(500, 100), 50, 40, true);
    Brush::drawRectangle(temp1, Rectangle(400, 230, 100, 200), 100, true);
    Brush::drawLine(temp1, Point(40, 300), Point(500, 300), 250, true);
    Brush::drawLine(temp1, Point(100, 100), Point(400, 10), 250, true);
    temp1.save("../BonusProblem2/Demo/8drawing.pgm");

    temp1 = Image::generateFilled(original.width(), original.height(), 20);
    Brush::drawCircle(temp1, Point(500, 100), 100, 33, false);
    Brush::drawCircle(temp1, Point(230, 200), 50, 40, false);
    Brush::drawRectangle(temp1, Rectangle(20, 230, 100, 14), 200, false);
    Brush::drawRectangle(temp1, Rectangle(400, 230, 24, 200), 64, false);
    Brush::drawRectangle(temp1, Rectangle(200, 230, 100, 222), 100, false);
    temp1.save("../BonusProblem2/Demo/9art_or_something.pgm");

}

int main() {
    ImageTests::execute();
    GeometryTests::execute();
    ImageProcessingTests::execute();
    BrushTests::execute();

//    demo();

    return 0;
}
