#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    // 将图像转换为灰度图
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);

    // 二值化图像
    cv::Mat binary;
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY);

    // 查找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 初始化矩形
    cv::Rect boundingRect;
    cv::RotatedRect minAreaRect;

    // 遍历所有轮廓
    for (const auto& contour : contours) {
        // 计算外接矩形
        cv::Rect rect = cv::boundingRect(contour);
        // 计算最小外接矩形
        cv::RotatedRect rotatedRect = cv::minAreaRect(contour);

        // 更新矩形
        if (rect.area() > boundingRect.area()) {
            boundingRect = rect;
        }
        if (rotatedRect.size.area() > minAreaRect.size.area()) {
            minAreaRect = rotatedRect;
        }
    }

    // 返回结果
    return {boundingRect, minAreaRect};
    
}