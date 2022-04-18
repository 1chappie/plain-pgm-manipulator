//
// Created by chappie on 26.03.2022.
//
#pragma once

#ifndef LABORATORY4_1CHAPPIE_IMAGE_H
#define LABORATORY4_1CHAPPIE_IMAGE_H

#include <string>
#include "Geometry.h"

#define UCHAR_CLAMP(val) (unsigned char)(val <= 0 ? 0 : val >= 255 ? 255 : val)

using std::string;

class Image {
public:
    friend class ImageTests;

    Image();

    /**
     * Initialize in memory an image with the given width and height.
     * @param width - width of the image
     * @param height - height of the image
     */
    Image(unsigned int w, unsigned int h);

    Image(const Image &other);

    /**
     * Initialize in memory an image with the given size.
     * @param size
     */
    Image(const Size &);

    ~Image();

    /**
     * Load an image from the given .pgm file.
     * Plain PGM format is required http://netpbm.sourceforge.net/doc/pgm.html.
     * @param path - path to the image file (must end in .pgm/.PGM)
     * @return true if the image was loaded successfully, false otherwise
     */
    bool load(const string &path);

    /**
     * Save the image to the given .pgm file. Plain PGM format is respected.
     * @param path - path to the image file (must end in .pgm/.PGM)
     * @return true if the image was saved successfully, false otherwise
     */
    bool save(const string &path);

    Image &operator=(const Image &other);

    friend bool operator==(const Image &A, const Image &B);

    friend bool operator!=(const Image &A, const Image &B);

    Image operator+(const Image &B);

    Image operator-(const Image &B);

    Image operator*(const Image &B);

    /**
     * Scalar addition.
     * @param b - scalar
     * @return This image with all elements increased by b.
     */
    Image operator+(const int &b);

    /**
     * Scalar subtraction.
     * @param b - scalar
     * @return This image with all elements decreased by b.
     */
    Image operator-(const int &b);

    /**
     * Scalar multiplication.
     * @param b - scalar
     * @return This image with all elements multiplied by b.
     */
    Image operator*(const int &b);

    /**
     * Return a new image that contain the pixels within a Region Of Interest specified as a parameter.
     * @overloads Image::getROI(Image, unsigned int, unsigned int, unsigned int, unsigned int)
     * @param[out] roiImg - output parameter for the ROI selection
     * @param[in] roiRect - ROI
     * @return true if the ROI was selected successfully, false otherwise
     */
    bool getROI(Image &roiImg, const Rectangle &roiRect);

    /**
     * Return a new image that contain the pixels within a Region Of Interest specified as a parameter.
     * @param[out] roiImg - output parameter for the ROI selection
     * @param[in] x - x coordinate of the top left corner of the ROI
     * @param[in] y - y coordinate of the top left corner of the ROI
     * @param[in] width - width of the ROI
     * @param[in] height - height of the ROI
     * @return true if the ROI was selected successfully, false otherwise
     */
    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

    /**
     * Returns whether the image object stores data or not.
     * @return true if the object's data pointer is null, false otherwise
     */
    bool isEmpty() const;

    /**
     * Returns a size object that contains the width and height of the image.
     * @return size object
     */
    Size size() const;

    /**
     * Returns the width of the image.
     * @return unsigned int
     */
    unsigned int width() const;

    /**
     * Returns the height of the image.
     * @return unsigned int
     */
    unsigned int height() const;

    /**
     * Return a reference to the pixel at the given coordinates.
     * @param y - y coordinate of the pixel
     * @param x - x coordinate of the pixel
     * @return reference to the pixel
     */
    unsigned char &at(unsigned int y, unsigned int x);

    /**
     * Return a constant reference to the pixel at the given coordinates.
     * @param y - y coordinate of the pixel
     * @param x - x coordinate of the pixel
     * @return constant reference to the pixel
     */
    unsigned char atConst(unsigned int y, unsigned int x) const;

    /**
     * Return a reference to the pixel at the given point.
     * @overloads Image::at(unsigned int, unsigned int)
     * @param pt - point in image
     * @return - reference to the pixel
     */
    unsigned char &at(Point pt);

    /**
     * Return a pointer to a row in the image.
     * @param y  - row index
     * @return - pointer to the row
     */
    unsigned char *row(int y);

    /**
     * Releases the memory allocated for the image. The image object becomes empty.
     */
    void release();

    /**
     * Recalculates the max value of the image.
     */
    void refresh();

    /**
     * Display the image pixels in a 2D grid.
     * @param os - output stream
     * @param dt - data
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Image &dt);

    /**
     * Initializes and returns an Image object filled with zeros.
     * @param width - width of the image
     * @param height - height of the image
     * @return Image object
     */
    static Image zeros(unsigned int width, unsigned int height);

    /**
     * Initializes and returns an Image object filled with ones.
     * @param width - width of the image
     * @param height - height of the image
     * @return Image object
     */
    static Image ones(unsigned int width, unsigned int height);

    /**
     * Initializes and returns an Image object filled with the max of unsigned char (255).
     * @param width - width of the image
     * @param height - height of the image
     * @return Image object
     */
    static Image max(unsigned int width, unsigned int height);

    /**
     * Initializes and returns an Image object filled with a specific value.
     * @param width - width of the image
     * @param height - height of the image
     * @param value - value to fill the image with
     * @return Image object
     */
    static Image generateFilled(unsigned int width, unsigned int height, unsigned int value);

private:

    unsigned char **m_data;
    unsigned int m_max_val;
    unsigned int m_width;
    unsigned int m_height;

};

#endif //LABORATORY4_1CHAPPIE_IMAGE_H
