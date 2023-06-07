#include "/opt/homebrew/include/raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int WIDTH = 1000;
const int HEIGHT = 1000;

float unit_cube[8][3] = {
    {1,1,0},
    {0,1,0},
    {0,0,0},
    {1,0,0},
    {1,0,1},
    {0,0,1},
    {0,1,1},
    {1,1,1},
};

void rotateZ(float cube[8][3], float angle){
    //rotation about z
    float x,y;
    for(int i = 0; i < 8; i++){
        x = cube[i][0];
        y = cube[i][1];
        cube[i][0] = x*cos(angle) - y*sin(angle);
        cube[i][1] = x*sin(angle) + y*cos(angle);
    }
}

void rotateY(float cube[8][3], float angle){
    //rotation about y
    float x,z;
    for(int i = 0; i < 8; i++){
        x = cube[i][0];
        z = cube[i][2];
        cube[i][0] = x*cos(angle) + z*sin(angle);
        cube[i][2] = - x*sin(angle) + z*cos(angle);
    }
}

void rotateX(float cube[8][3], float angle){
    //rotation about x
    float y,z;
    for(int i = 0; i < 8; i++){
        y = cube[i][1];
        z = cube[i][2];
        cube[i][1] = y*cos(angle) - z*sin(angle);
        cube[i][2] = y*sin(angle) + z*cos(angle);
    }
}

int main(void)
{

    InitWindow(WIDTH, HEIGHT, "CUBE3D");
    SetTargetFPS(60);
    float cube[8][3];
    //scale the cube and translate cube to middle
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 3; j++){
            cube[i][j] = 100*unit_cube[i][j] + 500;
        }
    }

    float angle = 0;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime(); // delta time
        BeginDrawing();
        ClearBackground(BLACK);
        for(int i = 0; i < 8; i++){
            DrawCircle(cube[i][0], cube[i][1], 5, WHITE);
        }
        for(int i = 0; i < 7; i++){
            DrawLine(cube[i][0], cube[i][1], cube[i+1][0], cube[i+1][1], WHITE);
        }
        DrawLine(cube[1][0], cube[1][1], cube[6][0], cube[6][1], WHITE);
        DrawLine(cube[0][0], cube[0][1], cube[7][0], cube[7][1], WHITE);
        DrawLine(cube[2][0], cube[2][1], cube[5][0], cube[5][1], WHITE);
            angle = angle + 0.01 * dt;
            // for(int i = 0; i < 8; i++){
            //     for(int j = 0; j < 3; j++){
            //         cube[i][j] -= 500;
            //     }
            // }
            rotateY(cube,angle);
            rotateX(cube,angle);
            rotateZ(cube,angle);
            // for(int i = 0; i < 8; i++){
            //     for(int j = 0; j < 3; j++){
            //         cube[i][j] += 500;
            //     }
            // }
        DrawFPS(10, 10);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
