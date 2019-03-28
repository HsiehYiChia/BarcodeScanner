#include <stdio.h>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

#define MODULE_SIZE 4

namespace bd
{

class BarcodeDecoder
{
private:

public:
    BarcodeDecoder();
    ~BarcodeDecoder();
    std::wstring Decode(cv::Mat barcode_img);
};

}