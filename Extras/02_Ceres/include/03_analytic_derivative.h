#include <ceres/ceres.h>

class QuadraticCostFunction : public ceres::SizedCostFunction<1, 1>
{
public:
    virtual ~QuadraticCostFunction() {}
    virtual bool Evaluate(double const *const *parameters,
                          double *residuals,
                          double **jacobians) const
    {
        const double x = parameters[0][0];
        residuals[0] = 10 - x;

        // Compute the Jacobian if asked for.
        if (jacobians != nullptr && jacobians[0] != nullptr)
        {
            jacobians[0][0] = -1;
        }
        return true;
    }
};