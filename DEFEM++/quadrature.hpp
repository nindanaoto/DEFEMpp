#pragma once
#include <array>
#include <cmath>
#include <functional>
#include "../thirdparties/eigen/Eigen/Core"
#include "../thirdparties/eigen/Eigen/Dense"
#include "quadrature/t2.hpp"
#include "utils.hpp"
namespace DEFEMpp{
    namespace Quadrature{
        enum class cell_type{triangle,tetrahedra};
        
        constexpr unsigned int cell_dim(cell_type cell){
            switch (cell)
            {
            case cell_type::triangle:
                return 2;
            case cell_type::tetrahedra:
                return 3;
            default:
                return 0;
            }
        }

        constexpr unsigned int num_quadrature_points(cell_type cell,unsigned int degree){
            switch (cell)
            {
            case cell_type::triangle:
                return DEFEMpp::Quadrature::T2::num_quadrature_points(degree);
            case cell_type::tetrahedra:
                return 0;
            default:
                return 0;;
            }
        }

        template<unsigned int dim>
        double get_volume(const std::array<std::array<double,dim>,dim+1>& nodes){
            // Compute the volume via the Cayley-Menger determinant
            // <http://mathworld.wolfram.com/Cayley-MengerDeterminant.html>. One advantage is
            // that it can compute the volume of the simplex indenpendent of the dimension of the
            // space in which it is embedded.
            Eigen::Matrix<double,dim+2,dim+2> matrix;
            matrix(0,0) = 0;
            for(int i = 1;i<dim+2;i++){
                matrix(0,i) = matrix(i,0) = 1;
            }
            for (int i = 0;i<dim+1;i++){
                matrix(i+1,i+1) = 0;
                for(int j = i+1; j<dim+1;j++){
                    double edge_norm = 0;
                    for (int k = 0; k<dim; k++) edge_norm += std::pow(nodes[i][k]-nodes[j][k],2);
                    matrix(i+1,j+1) = edge_norm;
                    matrix(j+1,i+1) = edge_norm;
                }
            }
            return std::sqrt((matrix.determinant()*DEFEMpp::Pow<-1,dim+1>::result)/((1<<dim)*DEFEMpp::factorial(dim)*factorial(dim)));
        }

        template<cell_type cell,unsigned int dim,unsigned int degree>
        std::pair<std::array<double,dim>,double> get_quadrature_point(const unsigned int index){
            switch (cell)
            {
            case cell_type::triangle:
                return DEFEMpp::Quadrature::T2::get_quadrature_point<degree>(index);
            case cell_type::tetrahedra:
                return {};
            default:
                return {};
            }
        }

        template<cell_type cell,unsigned int dim,unsigned int degree>
        double integrate(const std::function<double(const std::array<double,dim>&)>& func,const std::array<std::array<double,dim>,dim+1>& nodes){
            constexpr unsigned int num_points = num_quadrature_points(cell,degree);
            double res = 0;
            for(unsigned int i = 0;i < num_points;i++){
                const std::pair<std::array<double,dim>,double> quadrature_point = get_quadrature_point<cell,dim,degree>(i);
                res += quadrature_point.second*func(quadrature_point.first);
            }
            return get_volume<dim>(nodes)*res;
        }
    }
}