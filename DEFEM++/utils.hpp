namespace DEFMpp{
    //https://stackoverflow.com/a/1506856
    template<int X, int P>
    struct Pow
    {
        enum { result = X*Pow<X,P-1>::result };
    };
    template<int X>
    struct Pow<X,0>
    {
        enum { result = 1 };
    };
    template<int X>
    struct Pow<X,1>
    {
        enum { result = X };
    };
}