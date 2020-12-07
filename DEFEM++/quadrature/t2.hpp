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
            double get_quadrature_point(const unsigned int quadrature_index, const unsigned int coordinate_index){
                switch (degree)
                {
                case 0:
                case 1:
                    {
                        //Centroid
                        constexpr std::array<std::array<double,2>,1> quadrature_points_1 = {{1.0/3,1.0/3}};
                        return quadrature_points_1[quadrature_index][coordinate_index];
                    }
                case 2:
                    {
                        //hammer_marlowe_stroud_3
                        constexpr std::array<std::array<double,2>,3> quadrature_points_2 = {{{0.5,0.5},{0.5,0.0},{0.0,0.5}}};
                        return quadrature_points_2[quadrature_index][coordinate_index];
                    }
                case 3:
                    {
                        //strang_fix_cowper_04
                        constexpr std::array<std::array<double,2>,6> quadrature_points_3 = {{{0.659027622374092, 0.23193336855303043},{0.10903900907287761, 0.659027622374092},{0.23193336855303043, 0.10903900907287761},{0.23193336855303043, 0.659027622374092},{0.10903900907287761, 0.23193336855303043},{0.659027622374092  , 0.10903900907287761}}};
                        return quadrature_points_3[quadrature_index][coordinate_index];
                    }
                }
                return 0;
            }

            template<unsigned int degree>
            double get_quadrature_weight(const unsigned int quadrature_index){
                switch (degree)
                {
                case 0:
                case 1:
                    {
                        //Centroid
                        // constexpr std::array<double,1> quadrature_weights_1 = {1.0};
                        // return quadrature_weights_1[quadrarture_index];
                        return 1.;
                    }
                case 2:
                    {
                        //hammer_marlowe_stroud_3
                        // constexpr std::array<double,3> quadrature_weights_2 = {1.0/3,1.0/3,1.0/3};
                        // return quadrature_weights_2[quadrarture_index];
                        return 1./3;
                    }
                case 3:
                    {
                        //strang_fix_cowper_04
                        // constexpr std::array<double,6> quadrature_weights_3 = {1.0/6,1.0/6,1.0/6,1.0/6,1.0/6,1.0/6};
                        // return quadrature_weight_3[quadrarture_index];
                        return 1./6;
                    }
                }
                return 0;
            }
        }
    }
}