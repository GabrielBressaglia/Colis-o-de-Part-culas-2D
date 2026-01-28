#ifndef EquacoesAngulosParticulas_H
#define EquacoesAngulosParticulas_H

#include <math.h>
#define PI 3.141592653589793

/* A notacao eh a seguinte
 * V1 = (x_1, y_1)  VELOCIDADE PARTICULA 1
 * V2 = (x_2, y_2)  VELOCIDADE PARTICULA 2
 * C1 = (a_1, b_1)  CENTRO DA PARTICULA 1
 * C2 = (a_2, b_2)  CENTRO DA PARTICULA 2
 *
 * TETA_1 e TETA_2 estao em radianos
 * cos e sen trabalham com radianos aqui
 */

#define TETA(x, y) atan2((y), (x))
#define SIGMA(a1, b1, a2, b2) atan2((b2 - b1), (a2 - a1))
#define VEL_MOD(dx, dy) (sqrt((dx)*(dx) + (dy)*(dy)))

float Velocidade_Part_1_ComAng_X(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2);
float Velocidade_Part_1_ComAng_Y(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2);
float Velocidade_Part_2_ComAng_X(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2);
float Velocidade_Part_2_ComAng_Y(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2);

float Velocidade_Part_1_ComAng_X(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2)
{
    return (( ((VEL_MOD(x_1, y_1)*cos(TETA(x_1, y_1)-SIGMA(a_1, b_1, a_2, b_2))*(m1-m2) + 2*m2*VEL_MOD(x_2, y_2)*cos(TETA(x_2, y_2)-SIGMA(a_1, b_1, a_2, b_2))) / (m1 + m2))*cos(SIGMA(a_1, b_1, a_2, b_2))) + VEL_MOD(x_1, y_1)*sin(TETA(x_1, y_1)-SIGMA(a_1, b_1, a_2, b_2))*cos(SIGMA(a_1, b_1, a_2, b_2)+PI/2) );
}
float Velocidade_Part_1_ComAng_Y(float x_1, float y_1, float a_1, float b_1, float m1,
                                 float x_2, float y_2, float a_2, float b_2, float m2)
{
    return ( (((VEL_MOD(x_1, y_1)*cos(TETA(x_1, y_1)-SIGMA(a_1, b_1, a_2, b_2))*(m1-m2) + 2*m2*VEL_MOD(x_2, y_2)*cos(TETA(x_2, y_2)-SIGMA(a_1, b_1, a_2, b_2))) / (m1 + m2))*sin(SIGMA(a_1, b_1, a_2, b_2))) + VEL_MOD(x_1, y_1)*sin(TETA(x_1, y_1)-SIGMA(a_1, b_1, a_2, b_2))*sin(SIGMA(a_1, b_1, a_2, b_2)+PI/2) );
}
float Velocidade_Part_2_ComAng_X(float x_1, float y_1, float a_1, float b_1, float m1,
                                 float x_2, float y_2, float a_2, float b_2, float m2)
{
    return ( ((VEL_MOD(x_2, y_2)*cos(TETA(x_2, y_2)-SIGMA(a_1, b_1, a_2, b_2))*(m2-m1) + 2*m1*VEL_MOD(x_1, y_1)*cos(TETA(x_1, y_1)-SIGMA(a_1, b_1, a_2, b_2))) / (m1 + m2))*cos(SIGMA(a_1, b_1, a_2, b_2)) + VEL_MOD(x_2, y_2)*sin(TETA(x_2, y_2)-SIGMA(a_1, b_1, a_2, b_2))*cos(SIGMA(a_1, b_1, a_2, b_2)+PI/2) );
}
float Velocidade_Part_2_ComAng_Y(float x_1, float y_1, float a_1, float b_1, float m1,
                                 float x_2, float y_2, float a_2, float b_2, float m2)
{
    return ( ((VEL_MOD(x_2, y_2)*cos(TETA(x_2, y_2)-SIGMA(a_1, b_1, a_2, b_2))*(m2-m1) + 2*m1*VEL_MOD(x_1, y_1)*cos(TETA(x_1, y_1)-SIGMA(a_1, b_1, a_2, b_2))) / (m1 + m2))*sin(SIGMA(a_1, b_1, a_2, b_2)) + VEL_MOD(x_2, y_2)*sin(TETA(x_2, y_2)-SIGMA(a_1, b_1, a_2, b_2))*sin(SIGMA(a_1, b_1, a_2, b_2)+PI/2) );
}


#endif
