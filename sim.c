#include "raylib.h"
#include "Particulas.h"
#include "config.h"

int main(void)
{
    Particula Particulas[NUM_PART];
    Inicializar_Particula(Particulas);

    // Caracteristicas Simulacao
    InitWindow(WIDTH, HEIGHT, "Sim");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        Update_Particulas(Particulas);
        //Tratar_Colisoes(Particulas);
        Tratar_Colisoes_Ang(Particulas);

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

