//
// Created by chappie on 05.04.2022.
//

#include "ImageTests.h"

void ImageTests::execute() {
    std::cout << CYAN "Executing Image Tests..." NC << std::endl;
    ImageTests::test_constructors();
    ImageTests::test_save_load();
    ImageTests::test_operators();
    ImageTests::test_roi();
    ImageTests::test_getters();
    ImageTests::test_utility();
    std::cout << GREEN "Passed!" NC << std::endl;
}

void ImageTests::test_constructors() {
    Image voidImg;
    assert(voidImg.m_data == nullptr);
    assert(voidImg.m_width == 0);
    Image paramImg(10, 20);
    assert(paramImg.m_data != nullptr);
    assert(paramImg.m_width == 10);
    Image copyImg(paramImg);
    assert(copyImg.m_data != nullptr);
    assert(copyImg.m_width == 10);
    Image assignImg = paramImg;
    assert(assignImg.m_data != nullptr);
    assert(assignImg.m_width == 10);
    Image sizeImg(Size{10, 20});
    assert(sizeImg.m_data != nullptr);
    assert(sizeImg.m_width == 10);
}

void ImageTests::test_save_load() {
    Image img, img2, img3;
    img.load("../BonusProblem2/Tests/balo.pgm");
    //THIS ASSUMES THAT THE OUTPUT OF THE COMPILER IS SET TO THE 'cmake-build-debug-coverage' DIRECTORY,
    //CHANGE THE PATH, MOVE THE IMAGE, OR COMMENT THIS TEST OTHERWISE
    assert(img.m_width == 640);
    assert(img.m_max_val == 255);
    assert(img.m_data[0][0] == 232);
    img2 = img;
    img2.save("balo_copy.pgm");
    img3.load("balo_copy.pgm");
    assert(img3.m_data[23][23] == img.m_data[23][23]);
    assert(img.save("badname") == false);
    remove("balo_copy.pgm");
}

void ImageTests::test_utility() {
    Image temp = Image::generateFilled(3, 4, 5);
    assert(temp.m_width == 3);
    assert(temp.m_height == 4);
    assert(temp.m_data[2][1] == 5);
    temp = Image::zeros(2, 2);
    assert(temp.m_width == 2);
    assert(temp.m_data[0][1] == 0);
    temp = Image::ones(2, 2);
    assert(temp.m_data[0][1] == 1);
    temp = Image::max(1, 1);
    assert(temp.m_data[0][0] == 255);
    temp.m_data[0][0] = 2;
    temp.refresh();
    assert(temp.m_max_val == 2);
    temp.release();
    assert(temp.m_data == nullptr);
}

void ImageTests::test_operators() {
    Image temp(10, 20), temp2;
    temp.m_data[1][2] = 10;
    temp.refresh();
    temp2 = temp;
    assert(temp2.m_data[1][2] == 10);
    assert(temp2.m_width == 10);
    assert(temp == temp2);
    temp2.m_data[1][3] = 2;
    assert(temp2 != temp);
    temp = temp + Image::ones(10, 20);
    assert(temp.m_data[1][2] == 11);
    temp = temp - Image::generateFilled(10, 20, 3);
    assert(temp.m_data[1][2] == 8);
    temp = temp * Image::generateFilled(10, 20, 2);
    assert(temp.m_data[1][2] == 16);
    temp = temp + 10;
    assert(temp.m_data[1][2] == 26);
    temp = temp - 3;
    assert(temp.m_data[1][2] == 23);
    temp = temp * 3;
    assert(temp.m_data[1][2] == 69);

}

void ImageTests::test_getters() {
    Image temp(2, 3);
    temp.m_data[0][0] = 1;
    temp.m_data[0][1] = 2;
    unsigned char tempvect[3] = {1, 2, 3};
    assert(tempvect[0] == temp.row(0)[0]);
    assert(tempvect[1] == temp.row(0)[1]);
    assert(temp.width() == 2);
    assert(temp.height() == 3);
    assert(temp.size().getWidth() == 2);
    assert(temp.at(0, 1) == 2);
    temp.at(0, 1)++;
    assert(temp.atConst(0, 1) == 3);
    assert(temp.at(Point{1, 0}) == 3);
}

void ImageTests::test_roi() {
    Image temp = Image::generateFilled(4, 6, 1);
    temp.m_data[2][3] = 2;
    temp.m_data[2][1] = 12;
    temp.refresh();
    Image temp2, temp3;
    temp.getROI(temp2, 1, 1, 2, 2);
    assert(temp2.m_data[1][0] == 12);
    temp.getROI(temp2, 2, 2, 2, 2);
    assert(temp2.m_max_val == 2);
    temp.getROI(temp2, Rectangle{2, 2, 2, 2});
    assert(temp2.m_max_val == 2);
    temp.release();
    assert(temp.getROI(temp2, 2, 2, 2, 2) == false);
}
