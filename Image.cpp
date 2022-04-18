//
// Created by chappie on 26.03.2022.
//

#include "Image.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
#include <iomanip>

using std::cout, std::endl;

Image::Image() : m_width(0), m_height(0), m_max_val(0), m_data(nullptr) {}

Image::Image(unsigned int w, unsigned int h) : m_width(w), m_height(h), m_max_val(0) {
    this->m_data = new unsigned char *[h];
    for (int i = 0; i < h; i++)
        this->m_data[i] = new unsigned char[w]{0};
}

Image::Image(const Size &size) : m_width(size.width), m_height(size.height), m_max_val(0) {
    this->m_data = new unsigned char *[size.height];
    for (int i = 0; i < size.height; i++)
        this->m_data[i] = new unsigned char[size.width];
}

Image::Image(const Image &other) {
    this->m_height = other.m_height; //copy new height and width
    this->m_width = other.m_width;
    this->m_max_val = other.m_max_val;

    this->m_data = new unsigned char *[this->m_height]; //reallocate memory
    for (int i = 0; i < this->m_height; i++)
        this->m_data[i] = new unsigned char[this->m_width];

    for (int i = 0; i < this->m_height; i++) //copy the matrix
        for (int j = 0; j < this->m_width; j++)
            this->m_data[i][j] = other.m_data[i][j];
}

Image::~Image() {
    this->release();
}

// may be over-engineered - just be able to parse comments - ghinion
bool Image::load(const string &path) {
    //plain PGM as per http://netpbm.sourceforge.net/doc/pgm.html
    std::ifstream pgmSrc(path);
    string type = "0";
    unsigned int width = 0, height = 0;
    unsigned char maxval = 0;
    unsigned int temp_int;
    std::string temp_str;
    while (pgmSrc >> temp_str) {
        if (temp_str[0] == '#') {
            pgmSrc.ignore(1000, '\n'); //this handles comments, but it'll break if len(comment)>1000 :)
            continue;
        }
        if (type == "0") {
            type = temp_str;
            if (type != "P2") //only accepts plain PGM
                return false;
            continue;
        }
        if (!width) {
            width = std::stoi(temp_str);
            if (width < 1) return false;
            continue;
        }
        if (!height) {
            height = std::stoi(temp_str);
            if (height < 1) return false;
            continue;
        }
        if (!maxval) {
            temp_int = std::stoi(temp_str);
            maxval = UCHAR_CLAMP(temp_int);
            if ((int) maxval == 0) {
                *this = Image(width, height);
                return true;
            }
        }
        if (type != "0" && width && height && maxval)
            break;
    }
    if (type == "0" || !width || !height || !maxval) //if a file ends before these are given, load() fails
        return false;

    Image temp_image(width, height);
    temp_image.m_max_val = maxval;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pgmSrc.eof()) return false; //if height * width doesn't match the number of elems, return false
            pgmSrc >> temp_int;
            temp_image.m_data[i][j] = UCHAR_CLAMP(temp_int);
            if (temp_image.m_data[i][j] > maxval)
                temp_image.m_data[i][j] = maxval;
        }
    }

    *this = temp_image;
    pgmSrc.close();
    return true;
}

bool Image::save(const string &path) {
    //plain PGM as per http://netpbm.sourceforge.net/doc/pgm.html
    std::regex r("^.*\.(pgm|PGM)$");
    if (!std::regex_match(path, r)) //path must end in .pgm
        return false;
    if (this->isEmpty())
        return false;

    std::ofstream pgmBuild(path);

    pgmBuild << "P2\n";
    pgmBuild << this->m_width << " " << this->m_height << endl;
    pgmBuild << this->m_max_val << endl;
    for (int i = 0; i < this->m_height; i++) {
        for (int j = 0; j < this->m_width; j++)
            pgmBuild << std::setw(3) << (int) this->m_data[i][j] << " ";
        pgmBuild << endl;
    }

    pgmBuild.close();
    return true;
};

Image &Image::operator=(const Image &other) {
    if (this == &other)
        return *this;
    for (int i = 0; i < this->m_height; ++i)
        delete[] this->m_data[i];
    delete[] this->m_data;

    this->m_height = other.m_height;
    this->m_width = other.m_width;
    this->m_max_val = other.m_max_val;

    this->m_data = new unsigned char *[this->m_height];
    for (int i = 0; i < this->m_height; i++)
        this->m_data[i] = new unsigned char[this->m_width];
    for (int i = 0; i < this->m_height; i++)
        for (int j = 0; j < this->m_width; j++)
            this->m_data[i][j] = other.m_data[i][j];

    return *this;
}

bool operator==(const Image &A, const Image &B) {
    if (A.m_height != B.m_height ||
        A.m_width != B.m_width ||
        A.m_max_val != B.m_max_val)
        return false;
    for (int i = 0; i < A.m_height; i++)
        for (int j = 0; j < A.m_width; j++)
            if (A.m_data[i][j] != B.m_data[i][j])
                return false;
    return true;
}

bool operator!=(const Image &A, const Image &B) {
    return !(A == B);
}

Image Image::operator+(const Image &B) {
    if (this->m_height != B.m_height ||
        this->m_width != B.m_width)
        return *this; //returns the first addend if the sizes don't match
    //TODO throw exception?

    Image temp(this->m_width, this->m_height);
    int temp_int;
    for (int i = 0; i < this->m_height; i++)
        for (int j = 0; j < this->m_width; j++) {
            temp_int = (int) this->m_data[i][j] + (int) B.m_data[i][j];
            temp.m_data[i][j] = UCHAR_CLAMP(temp_int);
        }

    temp.refresh();
    return temp;
}

Image Image::operator-(const Image &B) {
    if (this->m_height != B.m_height ||
        this->m_width != B.m_width)
        return *this;

    Image temp(this->m_width, this->m_height);
    int temp_int;
    for (int i = 0; i < this->m_height; i++)
        for (int j = 0; j < this->m_width; j++) {
            temp_int = (int) this->m_data[i][j] - (int) B.m_data[i][j];
            temp.m_data[i][j] = UCHAR_CLAMP(temp_int);
        }

    temp.refresh();
    //TODO do ones(), 0 cant be opened
    return temp;
}

Image Image::operator*(const Image &B) {
    if (this->m_height != B.m_height ||
        this->m_width != B.m_width)
        return *this;

    Image temp(this->m_width, this->m_height);
    int temp_int;
    for (int i = 0; i < this->m_height; i++)
        for (int j = 0; j < this->m_width; j++) {
            temp_int = (int) this->m_data[i][j] * (int) B.m_data[i][j];
            temp.m_data[i][j] = UCHAR_CLAMP(temp_int);
        }

    temp.refresh();
    return temp;
}

Image Image::operator+(const int &b) {

    Image temp(this->m_width, this->m_height);
    int temp_int;
    for (int i = 0; i < this->m_height; i++)
        for (int j = 0; j < this->m_width; j++) {
            temp_int = (int) this->m_data[i][j] + b;
            temp.m_data[i][j] = UCHAR_CLAMP(temp_int);
        }

    temp.refresh();
    return temp;
}

Image Image::operator-(const int &b) {
    Image temp(this->m_width, this->m_height);
    int temp_int;
    for (int i = 0; i < this->m_height; i++)
        for (int j = 0; j < this->m_width; j++) {
            temp_int = (int) this->m_data[i][j] - b;
            temp.m_data[i][j] = UCHAR_CLAMP(temp_int);
        }

    temp.refresh();
    return temp;
}

Image Image::operator*(const int &b) {
    Image temp(this->m_width, this->m_height);
    int temp_int;
    for (int i = 0; i < this->m_height; i++)
        for (int j = 0; j < this->m_width; j++) {
            temp_int = (int) this->m_data[i][j] * b;
            temp.m_data[i][j] = UCHAR_CLAMP(temp_int);
        }

    temp.refresh();
    return temp;
}

bool Image::isEmpty() const {
    return m_data == nullptr;
}

unsigned int Image::width() const {
    return this->m_width;
}

unsigned int Image::height() const {
    return this->m_height;
}

unsigned char *Image::row(int y) {
    if (y > this->m_height - 1)
        throw std::out_of_range("Invalid index");
    return this->m_data[y];
}

void Image::release() {
    for (int i = 0; i < this->m_height; ++i)
        delete[] this->m_data[i];
    delete[] this->m_data;
    this->m_height = 0;
    this->m_width = 0;
    this->m_max_val = 0;
    this->m_data = nullptr;
}

void Image::refresh() {
    int max = -1;
    for (int i = 0; i < this->m_height; i++)
        for (int j = 0; j < this->m_width; j++)
            if (this->m_data[i][j] > max)
                max = this->m_data[i][j];
    this->m_max_val = max;
}

Size Image::size() const {
    return {this->m_width, this->m_height};
}

bool Image::getROI(Image &roiImg, const Rectangle &roiRect) {
    return this->getROI(roiImg, roiRect.cornerX, roiRect.cornerY, roiRect.width, roiRect.height);
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if (x + width > this->m_width || y + height > this->m_height)
        return false;
    if (!roiImg.isEmpty())
        roiImg.release();

    roiImg = Image(width, height);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            *(*(roiImg.m_data + i) + j) = *(*(this->m_data + y + i) + x + j); //pointer arithmetic
    roiImg.refresh();
    return true;
}

unsigned char &Image::at(unsigned int y, unsigned int x) {
    if (x > this->m_width - 1 || y > this->m_height - 1)
        throw std::out_of_range("Invalid index");
    return this->m_data[y][x];
}

unsigned char Image::atConst(unsigned int y, unsigned int x) const {
    if (x > this->m_width - 1 || y > this->m_height - 1)
        throw std::out_of_range("Invalid index");
    return this->m_data[y][x];
}

unsigned char &Image::at(Point pt) {
    return this->at(pt.y, pt.x);
}

std::ostream &operator<<(std::ostream &os, const Image &dt) {
    os << "Image: " << dt.m_width << "x" << dt.m_height << std::endl;
    for (int i = 0; i < dt.m_height; i++) {
        for (int j = 0; j < dt.m_width; j++)
            os << std::setw(3) << (int) dt.m_data[i][j] << " ";
        os << std::endl;
    }
    return os;
}

Image Image::zeros(unsigned int width, unsigned int height) {
    return generateFilled(width, height, 0);
}

Image Image::ones(unsigned int width, unsigned int height) {
    return generateFilled(width, height, 1);
}

Image Image::max(unsigned int width, unsigned int height) {
    return generateFilled(width, height, 255);
}

Image Image::generateFilled(unsigned int width, unsigned int height, unsigned int value) {
    Image temp(width, height);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            temp.m_data[i][j] = UCHAR_CLAMP(value);
    temp.m_max_val = UCHAR_CLAMP(value);
    return temp;
}

