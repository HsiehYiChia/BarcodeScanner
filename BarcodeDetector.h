#ifndef _BARCODE_DETECTOR_
#define _BARCODE_DETECTOR_
#pragma once
//-----------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
//-----------------------------------------------------------------------------
#include <vector>
//-----------------------------------------------------------------------------
struct BarcodeBoundingBox{
	cv::Point leftTop;
	cv::Point rightTop;
	cv::Point rightBottom;
	cv::Point leftBottom;
};
//-----------------------------------------------------------------------------
typedef std::vector<BarcodeBoundingBox> BarcodeLocation;
typedef std::vector<BarcodeLocation> BarcodeLocationVec;
typedef std::vector<cv::Mat> BarcodeImageVec;
//-----------------------------------------------------------------------------

// bd stands for Barcode Detector and Barcode Decodor
namespace bd
{

class BarcodeDetector
{
public:
	enum BarcodeType 
	{
		QRCode = 0,
		CODE39,
		CODE128,
		PDF417
	};

public:
	BarcodeDetector();
	~BarcodeDetector();

public:
	virtual BarcodeImageVec Detect(const cv::Mat &image) = 0;
	virtual BarcodeImageVec NormalizeImage(const BarcodeImageVec &images) = 0;
};

//-----------------------------------------------------------------------------
class QRCodeDetector : public BarcodeDetector 
{
public:
	BarcodeImageVec Detect(const cv::Mat &image);
	BarcodeImageVec NormalizeImage(const BarcodeImageVec &images);

private:
	cv::Mat PreProcess(const cv::Mat &image);
	BarcodeLocationVec LocateBarcode(const cv::Mat &image);
	BarcodeImageVec CropBarcode(const cv::Mat &image, BarcodeLocationVec locations);
};

}

#endif