template <typename T1, typename T2>
auto GetMax(T1 a, T2 b)
{
    return b < a ? a : b;
}