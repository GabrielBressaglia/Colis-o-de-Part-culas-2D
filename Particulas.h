#ifndef PARTICULAS_H
#define PARTICULAS_H

#include "raylib.h"
#include "GlobalVariables.h"

////////// DEFINICAO PARTICULA //////////
typedef struct{
    float x, y;
    float raio;
    float dx, dy;
}Particula;

void Inicializar_Particula(Particula*);
static void Update_Particula(Particula*);
static void Desenhar_Particula(const Particula*, Color);
void Update_Particulas(Particula*);
void Desenhar_Particulas(const Particula*);

////////// DEFINICAO FUNCOES ////////////
void Inicializar_Particula(Particula* P)
{
    for(int i = 0; i < NUM_PART; i++){
        P[i].x = WIDTH/2;
        P[i].y = HEIGHT/2;
        P[i].raio = 10;
        P[i].dx = GetRandomValue(-3, 3);
        P[i].dy = GetRandomValue(-3, 3);
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
        DrawCircle(Ps[i].x, Ps[i].y, Ps[i].raio, COR);
    }
}
#endif
