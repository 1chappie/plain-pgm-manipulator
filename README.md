# Plain PGM Manipulation

Plain PGM manipulation app that allows basic image processing and drawing.
>This program was done as an extra assignment for a lab at uni.

### Image
The header of this class has been inspired by the [Mat class from OpenCV](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html). 
Loading/saving is done as per the [plain PGM specification](http://netpbm.sourceforge.net/doc/pgm.html).

### Image Processing
The program allows for brightness and contrast processing, gamma correction processing and convolution (mean blur, gaussian blue, v-sobel and h-sobel kernels are included, as well as the possibility to load custom ones).

### Drawing
All drawing is done via the static functions of the Brush class. These rely on the Geometry module.
