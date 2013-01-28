// this program was developed as an excercize for G. Sappiros' course on Image&Video Processing @ Coursera.org by Marinos Koutomichalis (marinos@agxivatein.com)

// Compute the histogram of a given image and of its prediction errors. If the pixel being processed is at coordinate (0,0), consider
// predicting based on just the pixel at (-1,0);
// predicting based on just the pixel at (0,1);
// predicting based on the average of the pixels at (-1,0), (-1,1), and (0,1).

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

// ** this class is based on the 'opencv2 cookbook' p91

class Histogram1D {
private:
  // number of bins
  int histSize[1];  
  // min and max pixel value
  float hranges[2]; 
  const float* ranges[1];
public:
  Histogram1D() {
    histSize[0] = 256;
    hranges[0]= 0.0;
    hranges[1]= 255.0;
    ranges[0]= hranges;
  }
  // Computes the 3D histogram.
  cv::MatND getHistogram(const cv::Mat &image) {
    cv::MatND hist;
    int channels[1] = {0};
    // Compute histogram
    cv::calcHist(&image, 1, channels, cv::Mat(), hist, 1, histSize, ranges);
    return hist;
  }

  // Computes the 3D histogram and returns an image of it.
  cv::Mat getHistogramImage(const cv::Mat &image, cv::Scalar color){
         // Compute histogram first
         cv::MatND hist= getHistogram(image);
         // Get min and max bin values
         double maxVal=0;
         double minVal=0;
         cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);
         // Image on which to display histogram
         cv::Mat histImg(histSize[0], histSize[0],
                         CV_8UC3,cv::Scalar(0));
         // set highest point at 90% of nbins
         int hpt = static_cast<int>(0.9*histSize[0]);
         // Draw a vertical line for each bin
         for( int h = 0; h < histSize[0]; h++ ) {
            float binVal = hist.at<float>(h);
            int intensity = static_cast<int>(binVal*hpt/maxVal);
            // This function draws a line between 2 points
            cv::line(histImg,cv::Point(h,histSize[0]),
		     cv::Point(h,histSize[0]-intensity),
		     color);
	 }
	 return histImg;
}
};

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

  // split image
  std::vector<cv::Mat> rgbChannels(3);
  cv::split(image, rgbChannels);

  // histogram class
  Histogram1D h;

  // create windows
  cv::namedWindow( "Image",1);
  cv::namedWindow( "HistogramR");
  cv::moveWindow("HistogramR", 600, 0);
  cv::namedWindow( "HistogramG");
  cv::moveWindow("HistogramG", 600, 350);
  cv::namedWindow( "HistogramB");
  cv::moveWindow("HistogramB", 800, 200);

 
  // display images
  cv::imshow( "Image", image );                  
  cv::imshow("HistogramR", h.getHistogramImage(rgbChannels[2], 
					       cv::Scalar(0,0,255)));   
  cv::imshow("HistogramG", h.getHistogramImage(rgbChannels[1],
					       cv::Scalar(0,255,0)));   
  cv::imshow("HistogramB", h.getHistogramImage(rgbChannels[0],
					       cv::Scalar(255,0,0)));   
  cv::waitKey(0);  

  // clean up
  cv::destroyAllWindows();
  return 0;
}
