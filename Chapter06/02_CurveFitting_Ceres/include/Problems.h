#include <ceres/ceres.h>

namespace Problem
{
    // ���ۺ����ļ���ģ��
    struct CURVE_FITTING_COST
    {
        CURVE_FITTING_COST(double x, double y) : _x(x), _y(y) {}

        // �в�ļ���
        template <typename T>
        bool operator()(
            const T *const abc, // ģ�Ͳ�������3ά
            T *residual) const
        {
            // y-exp(ax^2+bx+c)
            residual[0] = T(_y) - ceres::exp(abc[0] * T(_x) * T(_x) + abc[1] * T(_x) + abc[2]);
            return true;
        }

        const double _x, _y; // x,y����
    };
};