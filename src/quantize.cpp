// this program was developed as an excercize for G. Sappiros' course on Image&Video Processing @ Coursera.org by Marinos Koutomichalis (marinos@agxivatein.com)

// Write a computer program capable of reducing the number of intensity levels in an image from 256 to 2, in integer powers of 2. The desired number of intensity levels needs to be a variable input to your program.

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <math.h>


int main( int argc, char** argv )
{
  // check if number of arguments is correct
  if( argc != 3)
    {
      std::cout <<"Wrong Number of arguments: correct syntax is: quantize *filename* *number of intensity levels*" << std::endl;
      return -1;
    }

  // read image
  cv::Mat image;
  image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);   

  // check if image was succesfully loaded
  if(! image.data )                              
    {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }

  // empty result image
  cv::Mat result ;
  result = image.clone();

  // new window
  cv::namedWindow( "Display window");

  // iterators
  cv::Mat_<cv::Vec3b>::iterator it=result.begin<cv::Vec3b>();
  cv::Mat_<cv::Vec3b>::iterator itend=result.end<cv::Vec3b>();
  
  // depending on the second argument - quantized image
  switch (atoi(argv[2])) {
  case 256:
    // display original
    cv::imshow( "Display window", image );                  
    cv::waitKey(0);                                          
    break;
  case 128:
    // 128 values
    for ( ; it!= itend; ++it) {
      (*it)[0] = ( (*it)[0] / 2 ) * 2;
      (*it)[1] = ( (*it)[1] / 2 ) * 2;
      (*it)[2] = ( (*it)[2] / 2 ) * 2;
    }
    break;
  case 64:
    // 64 values
    for ( ; it!= itend; ++it) {
      (*it)[0] = ( (*it)[0] / 4 ) * 4;
      (*it)[1] = ( (*it)[1] / 4 ) * 4;
      (*it)[2] = ( (*it)[2] / 4 ) * 4;
    } 
    break;
  case 32:
    // 32 values
    for ( ; it!= itend; ++it) {
      (*it)[0] = ( (*it)[0] / 8 ) * 8;
      (*it)[1] = ( (*it)[1] / 8 ) * 8;
      (*it)[2] = ( (*it)[2] / 8 ) * 8;
    }   
    break;
  case 16:
    // 16 values
    for ( ; it!= itend; ++it) {
      (*it)[0] = ( (*it)[0] / 16 ) * 16;
      (*it)[1] = ( (*it)[1] / 16 ) * 16;
      (*it)[2] = ( (*it)[2] / 16 ) * 16;
    }   
    break;
  case 8:
    // 8 values
    for ( ; it!= itend; ++it) {
      (*it)[0] = ( (*it)[0] / 32 ) * 32;
      (*it)[1] = ( (*it)[1] / 32 ) * 32;
      (*it)[2] = ( (*it)[2] / 32 ) * 32;
    }  
    break;
  case 4:
    // 4 values
    for ( ; it!= itend; ++it) {
      (*it)[0] = ( (*it)[0] / 64 ) * 64;
      (*it)[1] = ( (*it)[1] / 64 ) * 64;
      (*it)[2] = ( (*it)[2] / 64 ) * 64;
    }
    break;
  case 2:
    // 2 values
    for ( ; it!= itend; ++it) {
      (*it)[0] = ( (*it)[0] / 128 ) * 128;
      (*it)[1] = ( (*it)[1] / 128 ) * 128;
      (*it)[2] = ( (*it)[2] / 128 ) * 128;
    }   
    break;
  default:  // post an error if argument is different
    std::cout <<  "Number of Intensity levels should be an integer power of 2 and >=256" << std::endl ;
    return -1;    
  }

  // display original
  cv::putText(image, "Original Image: press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, 
	      cv::Scalar(0,100,250), 1, 8);
  cv::imshow( "Display window", image );                  
  cv::waitKey(0);                                          

  // display quantized image
  cv::putText(result, "Quantizedl Image: press any key to exit.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, 
	      cv::Scalar(0,100,250), 1, 8);
  cv::imshow( "Display window", result);                  
  cv::waitKey(0);  
  
  // clean up
  cv::destroyAllWindows();
  return 0;
}
