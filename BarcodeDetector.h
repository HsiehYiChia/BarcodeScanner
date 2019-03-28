#ifndef _BARCODE_DETECTOR_
#define _BARCODE_DETECTOR_
#pragma once
//-----------------------------------------------------------------------------
#include "opencv2\opencv.hpp"
//-----------------------------------------------------------------------------
#include <vector>
//-----------------------------------------------------------------------------
typedef std::vector<cv::Point> BarcodeLoc;
typedef std::vector<BarcodeLoc> BarcodeLocVec;
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
	virtual BarcodeLocVec Detect(cv::Mat image) = 0;
	virtual cv::Mat NormalizeImage(cv::Mat image) = 0;
};

}

#endif