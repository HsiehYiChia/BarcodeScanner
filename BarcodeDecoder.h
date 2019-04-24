#include <stdio.h>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>


namespace bd
{
#define MODULE_SIZE 4
#define THRESHOLD 200

struct Finder
{
    cv::Rect bb;
};

class BarcodeDecoder
{
private:
    std::vector<Finder> finder; /* There should be exactly 3 finder */
    std::vector<Finder> locate_finder(cv::Mat barcode_img);
public:
    BarcodeDecoder();
    ~BarcodeDecoder();
    std::wstring Decode(cv::Mat barcode_img);
};

}