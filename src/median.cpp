// this program was developed as an excercize for G. Sappiros' course on Image&Video Processing @ Coursera.org by Marinos Koutomichalis (marinos@agxivatein.com)

// Implement a median filter. Add different levels and types of noise to an image and experiment with different sizes of support for the median filter. 

// I only apply median filter to images here rather than adding noise because this is more interesting for my applications


#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


// median
cv::Mat medianColor(const cv::Mat &image) {
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
  if( argc != 3)
    {
      std::cout <<"Wrong Number of arguments: correct syntax is: median *filename* *median_window* (the last should be an odd number greater than 1)" << std::endl;
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

  // calculate median
  
  cv::Mat result;
  cv::medianBlur(image,result,atoi(argv[2]));

  // visualize images
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
