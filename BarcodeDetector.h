#ifndef _BARCODE_DETECTOR_
#define _BARCODE_DETECTOR_
#pragma once
//-----------------------------------------------------------------------------
#include "opencv2\opencv.hpp"
//-----------------------------------------------------------------------------
#include <vector>
//-----------------------------------------------------------------------------
struct BarcodeCorners{
	int leftTop;
	int rightTop;
	int rightBottom;
	int leftBottom;
};
//-----------------------------------------------------------------------------
typedef std::vector<BarcodeCorners> BarcodeLocation;
typedef std::vector<BarcodeLocation> BarcodeLocationVec;
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
	void SetBarcodeType(BarcodeType type);

protected:
	BarcodeType m_Type;

public:
	virtual BarcodeLocationVec Detect(cv::Mat image) = 0;
	virtual cv::Mat NormalizeImage(cv::Mat image) = 0;
};

class QRCodeDetector : public BarcodeDetector 
{
public:
	BarcodeLocationVec Detect(const cv::Mat &image);
	cv::Mat NormalizeImage(cv::Mat image);

private:
	cv::Mat PreProcess(const cv::Mat &image);
	BarcodeLocationVec LocateBarcode(const cv::Mat &image);
};

}

#endif