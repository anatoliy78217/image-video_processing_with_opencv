# this makefile is for mac with gcc and opecv installed with macports

all: 	
	#g++ src/quantize.cpp -o build/quantize -I/opt/local/include -L/opt/local/lib -lopencv_core -lopencv_imgproc -lopencv_calib3d -lopencv_video -lopencv_features2d -lopencv_ml -lopencv_highgui -lopencv_objdetect -lopencv_contrib -lopencv_legacy;
	#g++ src/average.cpp -o build/average -I/opt/local/include -L/opt/local/lib -lopencv_core -lopencv_imgproc -lopencv_calib3d -lopencv_video -lopencv_features2d -lopencv_ml -lopencv_highgui -lopencv_objdetect -lopencv_contrib -lopencv_legacy;
	#g++ src/jpeg_compression.cpp -o build/jpeg_compression -I/opt/local/include -L/opt/local/lib -lopencv_core -lopencv_imgproc -lopencv_calib3d -lopencv_video -lopencv_features2d -lopencv_ml -lopencv_highgui -lopencv_objdetect -lopencv_contrib -lopencv_legacy;

	#g++ src/histogram.cpp -o build/histogram -I/opt/local/include -L/opt/local/lib -lopencv_core -lopencv_imgproc -lopencv_calib3d -lopencv_video -lopencv_features2d -lopencv_ml -lopencv_highgui -lopencv_objdetect -lopencv_contrib -lopencv_legacy;

	g++ src/hist_equalization.cpp -o build/hist_equalization -I/opt/local/include -L/opt/local/lib -lopencv_core -lopencv_imgproc -lopencv_calib3d -lopencv_video -lopencv_features2d -lopencv_ml -lopencv_highgui -lopencv_objdetect -lopencv_contrib -lopencv_legacy;


clean:
	rm -rf *o
