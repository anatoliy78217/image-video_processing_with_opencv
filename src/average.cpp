// this program was developed as an excercize for G. Sappiros' course on Image&Video Processing @ Coursera.org by Marinos Koutomichalis (marinos@agxivatein.com)

// Using any programming language you fill comfortable with, perform a simple spatial 3x3 average of image pixels. In other words, replace the value of every pixel by the average of the values in its 3x3 neighborhood. If the pixel is located at (0,0), this means averaging the values of the pixels at the positions (-1,1), (0,1), (1,1), (-1,0), (0,0), (1,0), (-1,-1), (0,-1), and (1,-1). Be careful with pixels at the image boundaries. Repeat the process for a 10x10 neighborhood and again for a 20x20 neighborhood. Observe what happens to the image (we will discuss this in more details in the very near future, about week 3).

// first the original image is displayed and when some key is pressed the average one is display too


#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

int main( int argc, char** argv )
{
  if( argc != 2)
    {
      std::cout <<"Please enter filename!" << std::endl;
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

  // apply blurring
  cv::Mat result3;
  cv::Mat result10;
  cv::Mat result20;
  cv::blur(image, result3, cv::Size(3,3), cv::Point(0,0));
  cv::blur(image, result10, cv::Size(10,10), cv::Point(0,0));
  cv::blur(image, result20, cv::Size(20,20), cv::Point(0,0));
  
  // display images
  cv::putText(image, "Original Image: press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, 
	      cv::Scalar(0,100,250), 1, 8);
  cv::imshow( "Display window", image );                  
  cv::waitKey(0);  
  cv::putText(result3, "3x3 average: press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, 
	      cv::Scalar(0,100,250), 1, 8);   
  cv::imshow( "Display window", result3 );                  
  cv::waitKey(0);      
  cv::putText(result10, "10x10 average: press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, 
	      cv::Scalar(0,100,250), 1, 8);   
  cv::imshow( "Display window", result10 );                  
  cv::waitKey(0);      
  cv::putText(result20, "20x20 average: press any key to continue.", cv::Point(30,50), cv::FONT_HERSHEY_SIMPLEX, 0.8, 
	      cv::Scalar(0,100,250), 1, 8);   
  cv::imshow( "Display window", result20 );                  
  cv::waitKey(0);

   // clean up
  cv::destroyAllWindows();
  return 0;
}
