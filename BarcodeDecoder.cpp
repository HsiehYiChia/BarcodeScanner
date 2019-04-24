#include "BarcodeDecoder.h"

using namespace cv;
using namespace std;

namespace bd
{

vector<Finder> BarcodeDecoder::locate_finder(cv::Mat barcode_img)
{
    vector<KeyPoint> keypoints;
    cv::FAST(barcode_img, keypoints, 0, false);
    cout << keypoints.size() << endl;

    for (int i = 0; i < keypoints.size(); i++)
    {
        for (int j = i; j < keypoints.size(); j++)
        {
            double distance = norm(keypoints[i].pt - keypoints[j].pt);
        }
    }
}

BarcodeDecoder::BarcodeDecoder()
{
}

BarcodeDecoder::~BarcodeDecoder()
{
}

wstring BarcodeDecoder::Decode(cv::Mat barcode_img)
{
    threshold(barcode_img, barcode_img, THRESHOLD, 255, THRESH_BINARY);
    locate_finder(barcode_img);
    return wstring();
}

}