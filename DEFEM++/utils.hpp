namespace DEFEMpp{
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

    constexpr unsigned int factorial(unsigned int x){
        unsigned int res = 1;
        for(unsigned int i = 2;i<=x;i++) res*=i;
        return res;
    }
}