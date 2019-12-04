#include <pybind11/pybind11.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <string>
#include <iostream>

#include "opencv_converter.h"
namespace py = pybind11;

void show_image(cv::Mat image) {
    std::cout << image.rows << " " << image.cols << " " << image.channels() << std::endl;
}

cv::Mat read_image(std::string image_name) {
#if CV_MAJOR_VERSION < 4
    cv::Mat image = cv::imread(image_name, CV_LOAD_IMAGE_COLOR);
#else
    cv::Mat image = cv::imread(image_name, cv::IMREAD_COLOR);
#endif
    return image;
}

cv::Mat passthru(cv::Mat image) {
    return image;
}

cv::Mat cloneimg(cv::Mat image) {
    return image.clone();
}

//! 点相加
cv::Point addpt(cv::Point& lhs, cv::Point& rhs) {
    return cv::Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

//! 矩形相加
cv::Rect addrect(cv::Rect& lhs, cv::Rect& rhs) {
    int x = std::min(lhs.x, rhs.x);
    int y = std::min(lhs.y, rhs.y);
    int width  = std::max(lhs.x + lhs.width - 1,  rhs.x + rhs.width - 1) - x + 1;
    int height = std::max(lhs.y + lhs.height - 1, rhs.y + rhs.height - 1) - y + 1;
    return cv::Rect(x, y, width, height);
}

//! 矩阵相加
cv::Mat addmat(cv::Mat& lhs, cv::Mat& rhs) {
    return lhs + rhs;
}

//! 写入图片
void imwrite(std::string fpath, const cv::Mat& img) {
    cv::imwrite(fpath, img);
}

PYBIND11_MODULE(AuxoCv, m) {
    // NDArrayConverter::init_numpy();
    m.doc() = "pycv - A small OpenCV binding created using Pybind11";
    m.def("read_image", &read_image, "A function that read an image",
          py::arg("image"));

    m.def("show_image", &show_image, "A function that show an image",
          py::arg("image"));

    m.def("passthru", &passthru, "Passthru function", py::arg("image"));
    m.def("clone", &cloneimg, "Clone function", py::arg("image"));

    m.def("addpt", &addpt, "add two point");
    m.def("addrect", &addrect, "add two rect");
    m.def("addmat", &addmat, "add two matrix");
    m.def("imwrite", &imwrite, "write into the file");
}