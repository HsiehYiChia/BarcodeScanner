#include "BarcodeDecoder.h"

using namespace std;
using namespace cv;

namespace bd
{

BarcodeDecoder::BarcodeDecoder()
{
}

BarcodeDecoder::~BarcodeDecoder()
{
}

wstring BarcodeDecoder::Decode(cv::Mat barcode_img)
{
    threshold(barcode_img, barcode_img, THRESHOLD, 255, cv::THRESH_BINARY);
    vector<Finder> finder(3);
    /* up left finder */
    finder[0].bb = Rect(Point(43,43), Point(98, 98));
    /* up right finder */
    finder[1].bb = Rect(Point(251,43), Point(306, 98));
    /* bottom left finder */
    finder[2].bb = Rect(Point(43,251), Point(98, 306));

    vector<Mat> img(3);
    
    img[0] = barcode_img(finder[0].bb);
    img[1] = barcode_img(finder[1].bb);
    img[2] = barcode_img(finder[2].bb);
    imshow ("up_left_finder", img[0]);
    imshow ("up_right_finder", img[1]);
    imshow ("bottom_left_finder", img[2]);
    waitKey(0);

    return wstring();
}

}