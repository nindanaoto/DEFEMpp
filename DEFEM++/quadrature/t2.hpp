#include<array>
namespace DEFEMpp{
    namespace Quadrature{
        namespace T2{
            constexpr unsigned int num_quadrature_points(unsigned int degree){
                switch (degree)
                {
                case 0:
                case 1:
                    return 1;
                case 2:
                    return 3;
                case 3:
                    return 6;
                default:
                    return 0;
                }
            }

            template<unsigned int degree>
            std::pair<std::array<double,2>,double> get_quadrature_point(const unsigned int index){
                std::pair<std::array<double,2>,double> res;
                switch (degree)
                {
                case 0:
                case 1:
                    {
                        //Centroid
                        constexpr std::array<std::array<double,2>,1> quadrature_points_1 = {{1.0/3,1.0/3}};
                        constexpr std::array<double,1> quadrature_weights_1 = {1.0};
                        res.first = quadrature_points_1[index];
                        res.second = quadrature_weights_1[index];
                        break;
                    }
                case 2:
                    {
                        //hammer_marlowe_stroud_3
                        constexpr std::array<std::array<double,2>,3> quadrature_points_2 = {{{0.5,0.5},{0.5,0.0},{0.0,0.5}}};
                        constexpr std::array<double,3> quadrature_weights_2 = {1.0/3,1.0/3,1.0/3};
                        res.first = quadrature_points_2[index];
                        res.second = quadrature_weights_2[index];
                        break;
                    }
                }
                return res;
            }
        }
    }
}