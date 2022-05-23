// All my homies hate C++! 
#include "raylib.h"
#include <iostream>

using namespace std;


int main() // Method 
{

    // Game FPS 
    const int FPS = 60;


    // Game Window Dimensions 
    struct {
    int width = 800;
    int height = 450;
    Color background = WHITE;
    } gameWindow;


    // Blue Circle  
    struct {
    // Blue Circle Shape Positions
    int x, y, radius;
    Color color;
    } blueCircle;

    // Blue Circle Coordinates 
    blueCircle.x = float(gameWindow.width/2);
    blueCircle.y = float(gameWindow.width/2);
    blueCircle.radius = 25;
    
    // Blue Circle Color 
    blueCircle.color = BLUE;    

    // Blue Circle Edges 
    int l_circle_x = blueCircle.x - blueCircle.radius;
    int r_circle_x = blueCircle.x + blueCircle.radius;
    int u_circle_y = blueCircle.y - blueCircle.radius;
    int b_circle_y = blueCircle.y + blueCircle.radius;

    // Rectangle Structures 
    struct {
    int x, y, length; 
    Color color; 
    } redSquare; 

    // Red Square Coordinates  
    redSquare.x = 400;
    redSquare.y = 0;
    redSquare.length = 50; 

    // Red Square Color
    redSquare.color = RED;

    // Red Square Edges 
    int l_square_x = redSquare.x; 
    int r_square_x = redSquare.x + redSquare.length;
    int u_square_y = redSquare.y;
    int b_square_y = redSquare.y + redSquare.length;

    // Red Square Directional Movement
    int direction = 10;

    bool collision_with_square = 
                        (b_square_y >= u_circle_y) && 
                        (u_square_y <= b_circle_y) && 
                        (r_square_x >= l_circle_x) && 
                        (l_square_x <= r_circle_x);


    // Game Window   
    InitWindow(gameWindow.width, gameWindow.height, "Square Game"); // InitWindow will run for as long as the main() executes
    
    SetTargetFPS(FPS);

    cout << "Start of Window \n";    

    while (!WindowShouldClose())
    {
        // Setup the Drawing 
        BeginDrawing(); 
        ClearBackground(gameWindow.background);


        // Hit Collisions dddddddddddddd
        if (collision_with_square)
        {
            DrawText("Game Over", gameWindow.width/5, 200, 100, RED);
        }

        else 
        {
        
            // Update Positions
            l_circle_x = blueCircle.x - blueCircle.radius;
            r_circle_x = blueCircle.x + blueCircle.radius;
            u_circle_y = blueCircle.y - blueCircle.radius;
            b_circle_y = blueCircle.y + blueCircle.radius;

            l_square_x = redSquare.x; 
            r_square_x = redSquare.x + redSquare.length;
            u_square_y = redSquare.y; 
            b_square_y = redSquare.y + redSquare.length;

            // Update Collision 
            collision_with_square = 
                        (b_square_y >= u_circle_y) && 
                        (u_square_y <= b_circle_y) && 
                        (r_square_x >= l_circle_x) && 
                        (l_square_x <= r_circle_x);


            // Create Blue Circle with initial dimensions
            DrawCircle(blueCircle.x,blueCircle.y,blueCircle.radius,blueCircle.color);

            // Create Red Square with initial dimensions
            DrawRectangle(redSquare.x,redSquare.y,redSquare.length,redSquare.length,redSquare.color);


            // Movement Control 

            // Control Red Square Movement 
            redSquare.y += direction;

            if ( redSquare.y > gameWindow.height || redSquare.y < 0)
            {
                // Reverse direction 
                direction = -direction;
            }

            // Control Player Movement 
            if (IsKeyDown(KEY_D) && blueCircle.x + blueCircle.radius < gameWindow.width) // Right movement
            {
                blueCircle.x += 10;
            }

            if (IsKeyDown(KEY_A) && blueCircle.x - blueCircle.radius > 0)               // Left Movement 
            {
                blueCircle.x -= 10;
            }       
            
        }


        // Teardown 
        EndDrawing(); 

    }
    



}