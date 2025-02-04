template <typename T1,typename T2>
double max(T1 a, T2 b)
{
    if (static_cast<double>(a) > static_cast<double>(b))
        return static_cast<double>(a);
    else
        return static_cast<double>(b);
}