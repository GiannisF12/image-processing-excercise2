#include <stdio.h>
#include <vector>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;
using namespace std;

void meros1();
void meros2();

int main(int argc, char** argv )
{
    
    meros1();
    meros2();
    
    return 0;
}

void meros1()
{
    Mat image,image_blur,image_outline;
    image = imread("C:/Users/user/Desktop/UTH/epeksergasia_eikonas/ergasia2/HW2_images/cameraman.tif");


    if ( !image.data )
    {
        printf("No image data \n");
        std::exit(0);
    }

    GaussianBlur(image, image_blur, Size(3, 3), 0); 
   
    Mat morph = getStructuringElement( MORPH_RECT, Size( 5, 5 ), Point( 2, 2 ) );     

    morphologyEx(image_blur,image_outline, MORPH_GRADIENT,morph,Point(-1,-1), 1);

    imshow("outline", image_outline);
    waitKey();
}

void meros2()
{
    Mat image,image_sobel,image_canny;
    image = imread("C:/Users/user/Desktop/UTH/epeksergasia_eikonas/ergasia2/HW2_images/cameraman.tif");


    if ( !image.data )
    {
        printf("No image data \n");
        std::exit(0);
    }

    Sobel(image, image_sobel,CV_8U, 1, 1, 5);

    Canny(image,image_canny, 70, 30);

    imshow("Sobel", image_sobel);
    imshow("Canny", image_canny);
    waitKey();
}