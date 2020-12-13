#pragma once
#include"../utils.hpp"
#include<array>
#include<vector>
namespace DEFEMpp{
    namespace FiniteElement{
        namespace Lagrange{
            constexpr unsigned int get_num_dof(const unsigned int dim, const unsigned int degree){
                return DEFEMpp::multichoose(dim+1,degree);
            }
            //At higher order the equispaced Lagrange basis is poorly conditioned and creates unwanted oscillations in the solutions.
            template<unsigned int dim, unsigned int degree>
            struct Lagrange{
                std::array<double, get_num_dof(dim,degree)> Lagrange_points;
                std::array<std::vector<std::vector<unsigned int>>,dim+1> entity_node;
                
                constexpr Lagrange(){
                    
                }
            };
        }
    }
}