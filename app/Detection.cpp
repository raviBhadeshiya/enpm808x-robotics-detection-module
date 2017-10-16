/**
 * @file Detection.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include "Detection.hpp"

Detection::Detection() : Module() { this->isSetup_ = false; }

Detection::Detection(const cv::String& modelConfig, const cv::String& binary)
    : Module() {
  this->modelConfiguration_ = modelConfig;
  this->modelBinary_ = binary;
  this->isSetup_ = true;
  this->import();
}

Detection::~Detection() {}

auto Detection::import() -> void {
  // Create import object
  cv::Ptr<cv::dnn::Importer> importer;
  // Try to import the model
  try {
    // Importing model through caffeImporter
    importer = cv::dnn::createCaffeImporter(this->modelConfiguration_,
                                            this->modelBinary_);
  } catch (const cv::Exception& err) {
    // if any error print it out
    std::cerr << err.msg << std::endl;
  }
  // Init the Class's Deep Neural Net
  importer->populateNet(this->net_);

  // Clear the memory
  importer.release();
}

// Update evrything for detection
auto Detection::update(const cv::Mat& frame) -> cv::Mat {
  if (frame.channels() == 4) cvtColor(frame, frame, cv::COLOR_BGRA2BGR);
  // Genrate preprocess image
  cv::Mat preprocessedFrame = preProcess(frame);
  // Detect the object
  cv::Mat detectionMat = getObjects(preprocessedFrame);
  // Render box and return
  return render(frame, detectionMat);
}

// Overloaded update method for internal file
auto Detection::update() -> void {
  if (!this->frame_.empty()) this->frame_ = update(this->frame_);
}

// Detect the object and return object cv mat
auto Detection::getObjects(const cv::Mat& frame) -> cv::Mat {
  // Prepare blob
  cv::Mat inputBlob = cv::dnn::blobFromImage(
      frame, this->inScaleFactor_, cv::Size(this->inWidth_, this->inHeight_),
      this->meanVal_);  // Convert Mat to batch of images
  // Set input blob
  this->net_.setInput(inputBlob, "data");  // set the network input
  // Make forward pass
  cv::Mat detection = this->net_.forward("detection_out");  // compute output
  // Refomat the detection mat
  cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F,
                       detection.ptr<float>());
  // return detection mat
  return detectionMat;
}

// preProcess the image
auto Detection::preProcess(const cv::Mat& frame) -> cv::Mat {
  cv::Mat preProcessed;
  // Float conversion
  frame.convertTo(preProcessed, CV_32F);
  // Resize RGB_image ssd acceptable
  cv::resize(preProcessed, preProcessed, cv::Size(WIDTH_, HEIGHT_));
  // get mean values
  cv::Mat mean = getMean(WIDTH_, HEIGHT_);
  // subtract the mean value
  cv::subtract(preProcessed, mean, preProcessed);
  // return preProcessed image
  return preProcessed;
}

// Get the mean matrix
auto Detection::getMean(const int& width, const int& height) -> cv::Mat {
  cv::Mat mean;
  auto meanValues = {104, 117, 123};
  std::vector<cv::Mat> meanChannels;
  // create layer of image by mean value in cv_32f
  for (const auto& itr : meanValues) {
    cv::Mat channel(height, width, CV_32F, cv::Scalar(itr));
    meanChannels.push_back(channel);
  }
  // mearge channels for making single image
  cv::merge(meanChannels, mean);
  return mean;
}

auto Detection::render(cv::Mat frame, const cv::Mat& detectionMat) -> cv::Mat {
  // TODO(raviBhadeshiya) : Refractor required
  for (int i = 0; i < detectionMat.rows; i++) {
    // get confidence of detected object
    float confidence = detectionMat.at<float>(i, 2);
    // Render only with higher confidence level
    if (confidence > this->confidenceThreshold_) {
      // Get detected object class
      size_t objectClass = (size_t)(detectionMat.at<float>(i, 1));

      // Init corner point for bounding box
      float xLeftBottom = detectionMat.at<float>(i, 3) * frame.cols;
      float yLeftBottom = detectionMat.at<float>(i, 4) * frame.rows;
      float xRightTop = detectionMat.at<float>(i, 5) * frame.cols;
      float yRightTop = detectionMat.at<float>(i, 6) * frame.rows;

      // Float to string conversion
      std::ostringstream ss;
      ss << confidence;
      cv::String conf(ss.str());

      // Rectangle object for bounding box
      cv::Rect object(static_cast<int>(xLeftBottom),
                      static_cast<int>(yLeftBottom),
                      static_cast<int>(xRightTop - xLeftBottom),
                      static_cast<int>(yRightTop - yLeftBottom));

      // Render bounding box
      cv::rectangle(frame, object, cv::Scalar(0, 255, 0));

      // Generate label for bouding box
      cv::String label = cv::String(classNames_[objectClass]) + ": " + conf;
      int baseLine = 0;
      cv::Size labelSize =
          getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
      // Render the label over bounding box
      rectangle(
          frame,
          cv::Rect(cv::Point(xLeftBottom, yLeftBottom - labelSize.height),
                   cv::Size(labelSize.width, labelSize.height + baseLine)),
          cv::Scalar(255, 255, 255), CV_FILLED);
      putText(frame, label, cv::Point(xLeftBottom, yLeftBottom),
              cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
      // Print out the Class and confidence
      std::cout << "Class_Name: " << classNames_[objectClass]
                << " Confidence: " << confidence << std::endl;
    }
  }
  return frame;  // return frame
}

auto Detection::isSetup(void) -> bool { return isSetup_; }
