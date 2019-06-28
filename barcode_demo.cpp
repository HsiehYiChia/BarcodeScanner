#include <stdio.h>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include "BarcodeDetector.h"
#include "BarcodeDecoder.h"

using namespace cv;
using namespace std;
using namespace bd;

void usage(char** argv)
{
    printf("usage: %s <Image_path>\n", argv[0]);
}

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        usage(argv);
        return -1;
    }
    Mat img;
    img = imread( argv[1], 1 );

	//Start detect
	//-------------------------------------------------------------------------
	QRCodeDetector detector;
	detector.Detect(img);



    BarcodeDecoder decoder;
    decoder.Decode(img);
    
	return 0;
}