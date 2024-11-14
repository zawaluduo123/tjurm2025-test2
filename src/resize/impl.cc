#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    // 创建一个新的Mat对象，其尺寸为新计算的尺寸，类型与输入图像相同
    cv::Mat output(new_rows, new_cols, input.type(), cv::Scalar(0)); // 初始化为0

    // 遍历新图像的每个像素
    for (int i = 0; i < new_rows; ++i) {
        for (int j = 0; j < new_cols; ++j) {
            // 计算原始图像中对应的像素位置
            int x = static_cast<int>(j / scale);
            int y = static_cast<int>(i / scale);

            // 确保坐标在原始图像范围内
            if (x >= 0 && x < input.cols && y >= 0 && y < input.rows) {
                // 复制像素值
                output.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(y, x);
            }
        }
    }

    return output;
}