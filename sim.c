#include "raylib.h"
#include "Particulas.h"
#include "GlobalVariables.h"

int main(void)
{
    Particula Particulas[NUM_PART];
    Inicializar_Particula(Particulas);

    // Caracteristicas Simulacao
    InitWindow(WIDTH, HEIGHT, "Sim");
    SetTargetFPS(80);

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        Update_Particulas(Particulas);
        Tratar_Colisoes(Particulas);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(WHITE);
            Desenhar_Particulas(Particulas);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    CloseWindow();

    return 0;
}

