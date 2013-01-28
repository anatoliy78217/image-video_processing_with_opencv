// this program was developed as an excercize for G. Sappiros' course on Image&Video Processing @ Coursera.org by Marinos Koutomichalis (marinos@agxivatein.com)

/*
Do a basic implementation of JPEG.
-> Divide the image into 8x8 blocks.
-> Compute the DCT (discrete cosine transform) of each block. This is implemented in popular packages such as Matlab.
-> Quantize each block. You can do this using the tables in the video or simply divide each coefficient by N, round the result to the nearest integer, and multiply back by N. Try for different values of N.
-> You can also try preserving the 8 largest coefficients (out of the total of 8x8=64), and simply rounding them to the closest integer.
-> Visualize the results.
*/

// first the original image is displayed and when some key is pressed the resulting one 

// compression factor should a percentage

// I used opencv's jpeg encoding instead of implementing my own for now

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


int main( int argc, char** argv )
{
  if( argc != 3)
    {
      std::cout <<"Wrong Number of arguments: correct syntax is: jpeg_compression *filename* *compression factor (should be an integer percentage)*" << std::endl;
      return -1;
    }

  // read image
  cv::Mat image;
  image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);  

  if(! image.data )                              
    {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }

  cv::namedWindow( "Display window");

  // compression factor
  float factor = abs(atoi(argv[2])) % 101;

  // crop the image so that it is a multiple of 8x8
  int x = image.rows - (image.rows % 8);
  int y = image.cols - (image.cols % 8);

  cv::Mat roi = image( cv::Rect(0, 0, x, y));

  // convert to jpeg
  std::vector<uchar> buff;
  std::vector<int> param = std::vector<int>(2);
  param[0] = CV_IMWRITE_JPEG_QUALITY;
  param[1] = factor;
  
  cv::imencode(".jpg",roi,buff,param);
  cv::Mat result = cv::imdecode(cv::Mat(buff),CV_LOAD_IMAGE_COLOR);

  // display original
  cv::putText(roi, "Original Image: press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0,0,0), 1, 8);
  cv::imshow( "Display window", roi);                  
  cv::waitKey(0);  

  // visualize compressed image
  cv::putText(result, "Jpeg Compression: press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0,0,0), 1, 8);
  cv::imshow( "Display window", result);                  
  cv::waitKey(0);  
			     
  // clean up
  cv::destroyAllWindows();
  return 0;
}
