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

		//gaussianBlur the image
		cv::Size ksize = cv::Size(0, 0);
		double sigmaX = 3.0, sigmaY = 3.0;
		GaussianBlur(image, result, ksize, sigmaX, sigmaY);

		//binary the image by adaptive threshold
		int blockSize = imageWidth < imageHeight ? int(imageWidth / 10.0) : int(imageHeight / 10.0);
		blockSize = blockSize % 2 == 0 ? blockSize + 1 : blockSize;
		if (result.channels() == 3) cvtColor(result, result, CV_BGR2GRAY);
		adaptiveThreshold(result, result, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, 0);

		//do canny
		int cannyBottomTH = 50;
		int cannyUpperTH = 150;
		cv::Canny(result, result, cannyBottomTH, cannyUpperTH);

		return result;
	}
	catch (std::runtime_error &ex) {
		std::cout << "[Error]" << functionName << " : " << ex.what() << std::endl;
		throw ex;
	}
	catch (cv::Exception &ex) {
		std::cout << "[Error]" << functionName << " : " << ex.what() << std::endl;
		throw std::runtime_error(ex.what());
	}
}

BarcodeLocationVec QRCodeDetector::LocateBarcode(const cv::Mat &image)
{
	std::string functionName = "[QRCodeDetector::LocateBarcode]";
	BarcodeLocationVec result;
	try
	{
		//use opencv get contour
		std::vector<std::vector<cv::Point> > contours;
		std::vector<cv::Vec4i> hierarchy;
		findContours(image, contours, hierarchy, RetrievalModes::RETR_TREE, ContourApproximationModes::CHAIN_APPROX_SIMPLE);

		//go through all hierarchy

		//label QRCodes by calculating the distance between "positions"

		return result;
	}
	catch (std::runtime_error &ex) {
		std::cout << "[Error]" << functionName << " : " << ex.what() << std::endl;
		throw ex;
	}
	catch (cv::Exception &ex) {
		std::cout << "[Error]" << functionName << " : " << ex.what() << std::endl;
		throw std::runtime_error(ex.what());
	}
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