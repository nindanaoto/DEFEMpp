#include<quadrature.hpp>
#include<functional>
#include<array>
#include<cmath>
#include<cassert>
#include<iostream>

int main(){
    constexpr DEFEMpp::Quadrature::cell_type cell = DEFEMpp::Quadrature::cell_type::triangle;
    constexpr unsigned int dim = DEFEMpp::Quadrature::cell_dim(cell);
    constexpr unsigned int degree = 2;

    //Use x**n as test integrand.
    constexpr double analytic = 1./(degree+1) - 1./(degree+2);
    for(unsigned int variable = 0; variable<dim; variable++){
        const std::function<double(const std::array<double,dim>&)> func = [=](const std::array<double,dim>& point){return std::pow(point[variable],degree);};
        constexpr std::array<std::array<double,2>,3> nodes = {{{0,0},{0,1},{1,0}}};
        double numeric = DEFEMpp::Quadrature::integrate<cell,dim,degree>(func,nodes);
        std::cout<<analytic<<":"<<numeric<<std::endl;
    }
}