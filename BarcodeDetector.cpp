#include "BarcodeDetector.h"

namespace bd
{

BarcodeDetector::BarcodeDetector()
{

}
BarcodeDetector::~BarcodeDetector()
{

}

void BarcodeDetector::SetBarcodeType(BarcodeType type)
{
	m_Type = type;
}

BarcodeLocationVec QRCodeDetector::Detect(const cv::Mat &image)
{
	std::string functionName = "[QRCodeDetector::Detect]";
	BarcodeLocationVec result;
	try
	{
		//step0, check input image
		if (image.empty())	throw std::exception("Input image is empty!");
		
		//step1, do some image process, including white balance, sharpening, canny
		cv::Mat processedImage = PreProcess(image);

		//step2, get the location of the barcodes
		result = LocateBarcode(processedImage);

		return result;
	}
	catch (std::exception &ex) {
		std::cout << "[Error]" << functionName << " : " << ex.what() << std::endl;
		throw ex;
	}
}

cv::Mat QRCodeDetector::PreProcess(const cv::Mat &image)
{
	return cv::Mat();
}

BarcodeLocationVec QRCodeDetector::LocateBarcode(const cv::Mat &image)
{
	return BarcodeLocationVec();
}

}