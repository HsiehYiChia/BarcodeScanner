#include "BarcodeDetector.h"
//-----------------------------------------------------------------------------
#include <stdexcept>
//-----------------------------------------------------------------------------
using namespace cv;
using namespace std;
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
BarcodeImageVec QRCodeDetector::Detect(const cv::Mat &image)
{
	std::string functionName = "[QRCodeDetector::Detect]";
	BarcodeImageVec result;
	try
	{
		//step0, check input image
		if (image.empty())	throw std::runtime_error("Input image is empty!");
		
		//step1, do some image process
		cv::Mat processedImage = PreProcess(image);

		//step2, get the location of the barcodes
		BarcodeLocationVec barcodeLactions = LocateBarcode(processedImage);

		//step3, crop the barcodes
		BarcodeImageVec barcodeImages = CropBarcode(processedImage, barcodeLactions);

		//step4, normalize the barcode images
		return NormalizeImage(barcodeImages);
	}
	catch (std::runtime_error &ex) {
		std::cout << "[Error]" << functionName << " : " << ex.what() << std::endl;
		throw ex;
	}
}

cv::Mat QRCodeDetector::PreProcess(const cv::Mat &image)
{
	std::string functionName = "[QRCodeDetector::PreProcess]";
	Mat result;
	try
	{
		int imageWidth = image.size().width;
		int imageHeight = image.size().height;

		//sharpenize the image
		cv::Size ksize = cv::Size(0, 0);
		double sigmaX = 3.0, sigmaY = 3.0;
		GaussianBlur(image, result, ksize, sigmaX, sigmaY);
		addWeighted(image, 1.5, result, -0.5, 0, result);

		//binary the image by adaptive threshold
		int blockSize = imageWidth < imageHeight ? imageWidth / 10.0 : imageHeight / 10.0;
		blockSize = blockSize % 2 == 0 ? blockSize + 1 : blockSize;
		if (result.channels() == 3) cvtColor(result, result, CV_BGR2GRAY);
		adaptiveThreshold(result, result, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, 0);

		return result;
	}
	catch (std::runtime_error &ex) {
		std::cout << "[Error]" << functionName << " : " << ex.what() << std::endl;
		throw ex;
	}
}

BarcodeLocationVec QRCodeDetector::LocateBarcode(const cv::Mat &image)
{
	return BarcodeLocationVec();
}

BarcodeImageVec QRCodeDetector::CropBarcode(const cv::Mat &image, BarcodeLocationVec locations)
{
	return BarcodeImageVec();
}

BarcodeImageVec QRCodeDetector::NormalizeImage(const BarcodeImageVec &images)
{
	return BarcodeImageVec();
}

}