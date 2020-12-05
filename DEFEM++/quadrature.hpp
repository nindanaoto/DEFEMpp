#include<array>
#include <cmath>
#include<utils.hpp>
namespace DEFEMpp{
    //These assume each face is tringle.

    // Gauss-legendre quadrature has degree = 2 * npoints - 1
    // The extra + 1 deals with truncation.
    template<unsigned int degree>
    std::array<std::array<double,2>,(degree+1+1)/2> gauss_quadreture(){
        constexpr unsigned int num_points = (degree+1+1)/2; 
        std::array<double,(degree+1+1)/2> quadrature_points; //position and weight
        if constexpr(num_points==1) quadrature_points = {{0,1}};
        else if constexpr(num_points==2) quadrature_points = {{(1-1/std::sqrt(3))/2,1.0/2},{1+1/std::sqrt(3),1.0/2}};
        else if constexpr(num_points>2) static_assert(false,"Not implementetd number of points quadrature");
    }


    template<unsigned int dim, unsigned int degree>
    std::array<std::array<double,dim>,Pow(degree+1,dim-1)*degree> triangle_gauss_quadrature(dim,degree){
        static_assert(dim<2,"dim cannot be lower than 2!")
        static_assert(dim>3,"dim bigger than 3 is not implemented")
        //Because of Duffy transformation, degree is increased by 1 in dim-1 direction.
        constexpr std::array<degree+1> higher_quadrature_points = gauss_quadreture<degree>();
        constexpr std::array<degree> lower_quadrature_points = gauss_quadreture<degree>();
        std::array<std::array<double,dim>,Pow(degree+1,dim-1)*degree> quadrature_points;
        if constexpr(dim==2){
            
        }

        return quadrature_points;
    }

    template<unsigned int dim, unsigned int degree>
    struct triangle_quadrature
    {
        constexpr std::array<std::array<double,dim>,Pow(degree+1,dim-1)*degree> quadrature_points = triangle_gauss_quadrature<dim,degree>();
    };
}