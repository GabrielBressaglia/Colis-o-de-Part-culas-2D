#ifndef EQUACOESPARTICULAS2D_H
#define EQUACOESPARTICULAS2D_H

#define FLAG 1e-6f

/* A notacao eh a seguinte
 * V1 = (x_1, y_1)  VELOCIDADE PARTICULA 1
 * V2 = (x_2, y_2)  VELOCIDADE PARTICULA 2
 * C1 = (a_1, b_1)  CENTRO DA PARTICULA 1
 * C2 = (a_2, b_2)  CENTRO DA PARTICULA 2
*/

#define LAMBDA_V1(x_1, x_2, y_1, y_2, a_1, a_2, b_1, b_2, m1, m2) ((2.0f*m2 / (m1+m2)) * ((x_1 - x_2) * (a_1 - a_2) + (y_1 - y_2) * (b_1 - b_2)) / \
    ((a_1 - a_2) * (a_1 - a_2) + (b_1 - b_2) * (b_1 - b_2)))

#define LAMBDA_V2(x_1, x_2, y_1, y_2, a_1, a_2, b_1, b_2, m1, m2) ((2.0f*m1 / (m1+m2)) * ((x_2 - x_1) * (a_2 - a_1) + (y_2 - y_1) * (b_2 - b_1)) / \
((a_2 - a_1) * (a_2 - a_1) + (b_2 - b_1) * (b_2 - b_1)))

#define VER_FLAG(a_1, a_2, b_1, b_2) (((a_2)-(a_1))*((a_2)-(a_1)) + ((b_2)-(b_1))*((b_2)-(b_1)))

float Velocidade_Part_1_X(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2);
float Velocidade_Part_1_Y(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2);
float Velocidade_Part_2_X(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2);
float Velocidade_Part_2_Y(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2);

float Velocidade_Part_1_X(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2)
{
    if(VER_FLAG(a_1, a_2, b_1, b_2) < FLAG)
        return x_1;
    return x_1 - LAMBDA_V1(x_1, x_2, y_1, y_2, a_1, a_2, b_1, b_2, m1, m2) * (a_1 - a_2);
}
float Velocidade_Part_1_Y(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2)
{
    if(VER_FLAG(a_1, a_2, b_1, b_2) < FLAG)
        return y_1;
    return y_1 - LAMBDA_V1(x_1, x_2, y_1, y_2, a_1, a_2, b_1, b_2, m1, m2) * (b_1 - b_2);
}
float Velocidade_Part_2_X(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2)
{
    if(VER_FLAG(a_1, a_2, b_1, b_2) < FLAG)
        return x_2;
    return x_2 - LAMBDA_V2(x_1, x_2, y_1, y_2, a_1, a_2, b_1, b_2, m1, m2) * (a_2 - a_1);
}
float Velocidade_Part_2_Y(float x_1, float y_1, float a_1, float b_1, float m1,
                          float x_2, float y_2, float a_2, float b_2, float m2)
{
    if(VER_FLAG(a_1, a_2, b_1, b_2) < FLAG)
        return y_2;
    return y_2 - LAMBDA_V2(x_1, x_2, y_1, y_2, a_1, a_2, b_1, b_2, m1, m2) * (b_2 - b_1);
}

#endif
