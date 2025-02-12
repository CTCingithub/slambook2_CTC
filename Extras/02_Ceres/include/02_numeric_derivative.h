struct NumericDiffCostFunctor
{
    bool operator()(const double *const x, double *residual) const
    {
        residual[0] = 10.0 - x[0];
        return true;
    }
};
