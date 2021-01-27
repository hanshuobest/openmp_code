/************************************************************************************************
@filename    :openmp_for.cpp
@brief       :测试for循环
@time        :2021/01/27 16:55:48
@author      :hscoder
@versions    :1.0
@email       :hscoder@163.com
@usage       :如果for循环太小的话还不如不用
***********************************************************************************************/
#include <omp.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <ctime>
#include <chrono>

class Timer
{
    using Clock = std::chrono::high_resolution_clock;

public:
    void start()
    {
        start_ = Clock::now();
    }

    void end()
    {
        end_ = Clock::now();
    }

    double cost_time()
    {
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_);
        return duration.count();
    }

private:
    Clock::time_point start_, end_;
};

int main(int argc, char **argv)
{
    cv::Mat mat_img = cv::Mat::zeros(5000, 5000, CV_8UC1);
    int height = mat_img.rows;
    int width = mat_img.cols;

    Timer timer;
    timer.start();

    // method 1

    #if defined(_OPENMP)
    #pragma omp parallel for schedule(dynamic)
    #endif
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                mat_img.at<uchar>(i , j) = 255;
            }
        }


    // method2

// #if defined(_OPENMP)
// #pragma omp parallel
// #endif
//     {
// #pragma omp for
//         for (int i = 0; i < height; i++)
//         {
//             for (int j = 0; j < width; j++)
//             {
//                 mat_img.at<uchar>(i, j) = 255;
//             }
//         }
//     }

    timer.end();
    std::cout << "cost time: " << timer.cost_time() << std::endl;

    cv::imshow("image", mat_img);
    cv::waitKey(0);
    return 1;
}
