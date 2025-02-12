struct CostFunctor
{
    template <typename Type>
    bool operator()(const Type *const x, Type *residual) const
    {
        residual[0] = 10.0 - x[0];
        return true;
    }
};
