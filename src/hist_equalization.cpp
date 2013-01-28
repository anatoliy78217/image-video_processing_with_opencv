// this program was developed as an excercize for G. Sappiros' course on Image&Video Processing @ Coursera.org by Marinos Koutomichalis (marinos@agxivatein.com)

// Implement a histogram equalization function. 


#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


// equalize
cv::Mat equalizeColor(const cv::Mat &image) {
  std::vector<cv::Mat> result(3);
  std::vector<cv::Mat> bgr(3);
  cv::Mat final;
  cv::split(image, bgr);
  cv::equalizeHist(bgr[0],result[0]);
  cv::equalizeHist(bgr[1],result[1]);
  cv::equalizeHist(bgr[2],result[2]);
  cv::merge(result,final);
  return final;
}


int main( int argc, char** argv )
{
  if( argc != 2)
    {
      std::cout <<"Wrong Number of arguments: correct syntax is: jpeg_compression *filename* )*" << std::endl;
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
  
  // create window
  cv::namedWindow( "Display window");

  // equalize image
  cv::Mat result;
  result = equalizeColor(image);


  // visualize original and then eualized image
  cv::putText(image, "press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0,0,0), 1, 8);
  cv::imshow( "Display window", image);                  
  cv::waitKey(0);  
			     
  cv::putText(result, "press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0,0,0), 1, 8);
  cv::imshow( "Display window", result);                  
  cv::waitKey(0);  

  // clean up
  cv::destroyAllWindows();
  return 0;
}
