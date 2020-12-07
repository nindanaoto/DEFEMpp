#include<array>
namespace DEFEMpp{
    namespace Quadrature{
        namespace T3{
            constexpr unsigned int num_quadrature_points(unsigned int degree){
                switch (degree)
                {
                case 0:
                case 1:
                    return 1;
                case 2:
                    return 4;
                case 3:
                    return 8;
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
                        //keast_0
                        constexpr std::array<std::array<double,3>,1> quadrature_points_1 = {{1.0/4,1.0/4,1.0/4}};
                        return quadrature_points_1[quadrature_index][coordinate_index];
                    }
                case 2:
                    {
                        //hammer_marlowe_stroud_1
                        constexpr double r = 1./std::sqrt(5);
                        constexpr double a_1 = (1-r)/4;
                        constexpr double b_1 = 1 - 3*a_1;
                        constexpr std::array<std::array<double,3>,4> quadrature_points_2 = {{{a_1,a_1,a_1},{a_1,a_1,b_1},{a_1,b_1,a_1},{b_1,a_1,a_1}}};
                        return quadrature_points_2[quadrature_index][coordinate_index];
                    }
                case 3:
                    {
                        //witherden_vincent_03
                        constexpr std::array<std::array<double,3>,8> quadrature_points_3 = {{{0.3281633025163817, 0.3281633025163817, 0.3281633025163817}, {0.1080472498984286  , 0.1080472498984286  , 0.1080472498984286},{0.3281633025163817  , 0.3281633025163817  , 0.015510092450854884}, {0.1080472498984286, 0.1080472498984286  , 0.6758582503047142},{0.3281633025163817  , 0.015510092450854884, 0.3281633025163817},{0.1080472498984286  , 0.6758582503047142  , 0.1080472498984286},{0.015510092450854884, 0.3281633025163817  , 0.3281633025163817},{0.6758582503047142  , 0.1080472498984286  , 0.1080472498984286}}};
                        constexpr std::array<double,8> quadrature_weights_3 = {0.1362178425370874, 0.1137821574629126, 0.1362178425370874, 0.1137821574629126, 0.1362178425370874, 0.1137821574629126, 0.1362178425370874, 0.1137821574629126};
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
                        //keast_0
                        // constexpr std::array<double,1> quadrature_weights_1 = {1.0};
                        // return quadrature_points_1[quadrature_index][coordinate_index];
                        return 1.0;
                    }
                case 2:
                    {
                        //hammer_marlowe_stroud_1
                        // constexpr std::array<double,4> quadrature_weights_2 = {1.0/4,1.0/4,1.0/4,1.0/4};
                        // return quadrature_points_2[quadrature_index][coordinate_index];
                        return 1.0/4;
                    }
                case 3:
                    {
                        //witherden_vincent_03
                        constexpr std::array<double,8> quadrature_weights_3 = {0.1362178425370874, 0.1137821574629126, 0.1362178425370874, 0.1137821574629126, 0.1362178425370874, 0.1137821574629126, 0.1362178425370874, 0.1137821574629126};
                        return quadrature_weights_3[quadrature_index];
                    }
                }
                return 0;
            }
        }
    }
}