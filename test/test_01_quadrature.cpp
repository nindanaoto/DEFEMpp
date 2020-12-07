#include<quadrature/quadrature.hpp>
#include<functional>
#include<array>
#include<cmath>
#include<cassert>
#include<iostream>

int main(){
    constexpr DEFEMpp::Quadrature::cell_type cell = DEFEMpp::Quadrature::cell_type::tetrahedron;
    constexpr unsigned int dim = DEFEMpp::Quadrature::cell_dim(cell);
    constexpr unsigned int degree = 3;

    //Use x**n as test integrand.
    double analytic = 1./(degree+1);
    for(int i = 1; i<dim; i++) analytic *= 1./(degree+1+i);
    for(unsigned int variable = 0; variable<dim; variable++){
        const std::function<double(const std::array<double,dim>&)> func = [=](const std::array<double,dim>& point){return std::pow(point[variable],degree);};
        // constexpr std::array<std::array<double,2>,3> nodes = {{{0,0},{0,1},{1,0}}};
        constexpr std::array<std::array<double,3>,4> nodes = {{{0,0,0},{1,0,0},{0,1,0},{0,0,1}}};
        double numeric = DEFEMpp::Quadrature::integrate<cell,dim,degree>(func,nodes);
        std::cout<<analytic<<":"<<numeric<<":"<<analytic-numeric<<std::endl;
    }
}