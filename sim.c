#include "raylib.h"
#include "Particulas.h"
#include "GlobalVariables.h"

int main(void)
{
    Particula Particulas[NUM_PART];
    Inicializar_Particula(Particulas);

    // Caract Simulacao
    InitWindow(WIDTH, HEIGHT, "Sim");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Update_Particulas(Particulas);
        Desenhar_Particulas(Particulas);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

