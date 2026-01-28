#ifndef PARTICULAS_H
#define PARTICULAS_H

#include "raylib.h"
#include "GlobalVariables.h"
#include "EquacoesParticulas2D.h"
#include "EquacoesAngulosParticulas.h"

////////// DEFINICAO PARTICULA //////////
typedef struct{
    float x, y;
    float raio;
    float dx, dy;
    float mass;
}Particula;

void Inicializar_Particula(Particula*);
static void Update_Particula(Particula*);
static void Desenhar_Particula(const Particula*, Color);
void Update_Particulas(Particula*);
void Desenhar_Particulas(const Particula*);
void Tratar_Colisoes(Particula*);
void Tratar_Colisoes_Ang(Particula*);

////////// DEFINICAO FUNCOES ////////////
void Inicializar_Particula(Particula* P)
{
    // PROBLEMA:
    //  |
    //  V
    // GetRandomValue eh um metodo INTEIRO ou seja retorna apenas INTEIROS!!
    for(int i = 0; i < NUM_PART; i++){
        P[i].x = GetRandomValue(1, WIDTH -1);
        P[i].y = GetRandomValue(1, HEIGHT -1);
        P[i].raio = 10;//GetRandomValue(7, 10);
        P[i].dx = GetRandomValue(-10, 10);
        P[i].dy = GetRandomValue(-10, 10);
        P[i].mass = 1;//GetRandomValue(1, 3);
    }
}
static void Update_Particula(Particula* P)
{
    float x_old = P->x;
    float y_old = P->y;

    P->x += P->dx;
    P->y += P->dy;

    // Verificar se passou dos limites
    // Aqui eu levo em conta a esfera como um todo
    // Pode nao ficar legal para simulacoes graficas
    if(P->x < 0 + P->raio || P->x > WIDTH - P->raio){
        P->x = x_old;
        // deflete a esfera
        P->dx = -P->dx;
    }
    if(P->y < 0 +  P->raio|| P->y > HEIGHT -  P->raio){
        P->y = y_old;
        P->dy = -P->dy;
    }
}
static void Desenhar_Particula(const Particula* P, Color cor)
{
    DrawCircle(P->x, P->y, P->raio, cor);
}
void Update_Particulas(Particula* Ps)
{
    for(int i = 0; i < NUM_PART; i++){
        Update_Particula(&Ps[i]);
    }
}

void Desenhar_Particulas(const Particula* Ps)
{
    for(int i = 0; i < NUM_PART; i++){
        if(i % 2 == 0)
            DrawCircle(Ps[i].x, Ps[i].y, Ps[i].raio, BLUE);
        else
            DrawCircle(Ps[i].x, Ps[i].y, Ps[i].raio, RED);
    }
}
void Tratar_Colisoes(Particula* P)
{
    for(int i = 0; i < NUM_PART; i++){
        for(int j = NUM_PART - 1; j >= i + 1; j--){
            // Nao se deve apenas Verificar se as particulas colidem
            // Precisa Verificar se elas ja colidiram, para nao "Grudarem"
            // Ou seja, evitar que sejam atualizadas incorretamente mais de uma vez
            float dvx = P[i].dx - P[j].dx;
            float dvy = P[i].dy - P[j].dy;

            float dcx = P[i].x - P[j].x;
            float dcy = P[i].y - P[j].y;

            float aproximando = dvx * dcx + dvy * dcy;

            // 3. Só resolve colisão se estiverem se aproximando
            if (aproximando < 0.0f){
                if(CheckCollisionCircles((Vector2){P[i].x, P[i].y}, P[i].raio, (Vector2){P[j].x, P[j].y}, P[j].raio)){
                    P[i].dx = Velocidade_Part_1_X(P[i].dx, P[i].dy, P[i].x, P[i].y, P[i].mass, P[j].dx, P[j].dy, P[j].x, P[j].y, P[j].mass);
                    P[i].dy = Velocidade_Part_1_Y(P[i].dx, P[i].dy, P[i].x, P[i].y, P[i].mass, P[j].dx, P[j].dy, P[j].x, P[j].y, P[j].mass);
                    P[j].dx = Velocidade_Part_2_X(P[i].dx, P[i].dy, P[i].x, P[i].y, P[i].mass, P[j].dx, P[j].dy, P[j].x, P[j].y, P[j].mass);
                    P[j].dy = Velocidade_Part_2_Y(P[i].dx, P[i].dy, P[i].x, P[i].y, P[i].mass, P[j].dx, P[j].dy, P[j].x, P[j].y, P[j].mass);

                }
            }
        }
    }
}
void Tratar_Colisoes_Ang(Particula* P)
{
    for(int i = 0; i < NUM_PART; i++){
        for(int j = NUM_PART - 1; j >= i + 1; j--){
            // Nao se deve apenas Verificar se as particulas colidem
            // Precisa Verificar se elas ja colidiram, para nao "Grudarem"
            // Ou seja, evitar que sejam atualizadas incorretamente mais de uma vez
            float dvx = P[i].dx - P[j].dx;
            float dvy = P[i].dy - P[j].dy;

            float dcx = P[i].x - P[j].x;
            float dcy = P[i].y - P[j].y;

            float aproximando = dvx * dcx + dvy * dcy;

            // 3. Só resolve colisão se estiverem se aproximando
            if (aproximando < 0.0f){
                if(CheckCollisionCircles((Vector2){P[i].x, P[i].y}, P[i].raio, (Vector2){P[j].x, P[j].y}, P[j].raio)){
                    P[i].dx = Velocidade_Part_1_ComAng_X(P[i].dx, P[i].dy, P[i].x, P[i].y, P[i].mass, P[j].dx, P[j].dy, P[j].x, P[j].y, P[j].mass);
                    P[i].dy = Velocidade_Part_1_ComAng_Y(P[i].dx, P[i].dy, P[i].x, P[i].y, P[i].mass, P[j].dx, P[j].dy, P[j].x, P[j].y, P[j].mass);
                    P[j].dx = Velocidade_Part_2_ComAng_X(P[i].dx, P[i].dy, P[i].x, P[i].y, P[i].mass, P[j].dx, P[j].dy, P[j].x, P[j].y, P[j].mass);
                    P[j].dy = Velocidade_Part_2_ComAng_Y(P[i].dx, P[i].dy, P[i].x, P[i].y, P[i].mass, P[j].dx, P[j].dy, P[j].x, P[j].y, P[j].mass);

                }
            }
        }
    }
}
#endif
