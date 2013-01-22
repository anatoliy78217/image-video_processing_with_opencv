// this program was developed as an excercize for G. Sappiros' course on Image&Video Processing @ Coursera.org by Marinos Koutomichalis (marinos@agxivatein.com)

// Using any programming language you fill comfortable with, perform a simple spatial 3x3 average of image pixels. In other words, replace the value of every pixel by the average of the values in its 3x3 neighborhood. If the pixel is located at (0,0), this means averaging the values of the pixels at the positions (-1,1), (0,1), (1,1), (-1,0), (0,0), (1,0), (-1,-1), (0,-1), and (1,-1). Be careful with pixels at the image boundaries. Repeat the process for a 10x10 neighborhood and again for a 20x20 neighborhood. Observe what happens to the image (we will discuss this in more details in the very near future, about week 3).

// first the original image is displayed and when some key is pressed the average one is display too


#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
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

  // 3x3
  cv::Mat result3;
  result3 = image.clone();
  unsigned int color3[3] = {0,0,0};
  for (int k = 0; k<3; k++) {
    for (int j = 1; j<image.rows; j++) {
      for (int i = 1; i<image.cols; i++) {
	for (int a = -1; a<2; a++) {
	  for (int b = -1; b<2; b++) {
	    color3[k] = color3[k] + image.at<cv::Vec3b>(j+a,i+b)[k];
	  }
	}
	color3[k] = color3[k] / 10;
	result3.at<cv::Vec3b>(j,i)[k] = color3[k];
      }
    } 
  }

  // 10x10
  cv::Mat result10;
  result10 = image.clone();
  unsigned int color10[3] = {0,0,0};
  for (int k = 0; k<3; k++) {
    for (int j = 5; j<image.rows-5; j++) {
      for (int i = 5; i<image.cols-5; i++) {
	for (int a = -5; a<5; a++) {
	  for (int b = -5; b<5; b++) {
	    color10[k] = color10[k] + image.at<cv::Vec3b>(j+a,i+b)[k];
	  }
	}
	color10[k] = color10[k] / 101;
	result10.at<cv::Vec3b>(j,i)[k] = color10[k];
      }
    } 
  }

  // 20x20
  cv::Mat result20;
  result20 = image.clone();
  unsigned int color20[3] = {0,0,0};
  for (int k = 0; k<3; k++) {
    for (int j = 10; j<image.rows-10; j++) {
      for (int i = 10; i<image.cols-10; i++) {
	for (int a = -10; a<10; a++) {
	  for (int b = -10; b<10; b++) {
	    color20[k] = color20[k] + image.at<cv::Vec3b>(j+a,i+b)[k];
	  }
	}
	color20[k] = color20[k] / 401;
	result20.at<cv::Vec3b>(j,i)[k] = color20[k];
      }
    } 
  }
  
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
