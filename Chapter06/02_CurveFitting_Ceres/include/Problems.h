#include <ceres/ceres.h>

namespace Problem
{
    struct Quad_Minimum
    // Find minimum of f(x) = \frac{1}{2} (10 - x)^2
    {
        template <typename T>
        bool operator()(const T *const x, T *residual) const
        {
            residual[0] = 10.0 - x[0];
            return true;
        }
    };
};