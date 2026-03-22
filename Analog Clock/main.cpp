#include "raylib.h"
#include "analog.hpp"


Color demo1 = {131,125,237,255};

int main() {
    InitWindow(600, 600, "Analog Clock");
    SetTargetFPS(15);

    AnalogClock clock(250, {300, 300});


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(demo1);
        clock.Update();
        clock.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
