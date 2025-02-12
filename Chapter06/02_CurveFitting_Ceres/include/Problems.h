#include <ceres/ceres.h>

namespace Problem
{
    // 代价函数的计算模型
    struct CURVE_FITTING_COST
    {
        CURVE_FITTING_COST(double x, double y) : _x(x), _y(y) {}

        // 残差的计算
        template <typename T>
        bool operator()(
            const T *const abc, // 模型参数，有3维
            T *residual) const
        {
            // y-exp(ax^2+bx+c)
            residual[0] = T(_y) - ceres::exp(abc[0] * T(_x) * T(_x) + abc[1] * T(_x) + abc[2]);
            return true;
        }

        const double _x, _y; // x,y数据
    };
};