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


    // Circle Structure 
    struct {
    int x, y, radius;                   // Circle Coordinates and Size
    Color color;                        // Circle Color                                          
    int left = x - radius;              // Left edge of the circle
    int right = x + radius;             // Right edge of the circle
    int top = y - radius;               // Top of the circle
    int bottom = y + radius;            // Bottom of the circle 
    } blueCircle, orangeCircle;         // Creating Blue and Orange Circle Entities 


    // Blue Circle Structure
    blueCircle.x = float(gameWindow.width/2);                   // Blue Starting x position
    blueCircle.y = float(gameWindow.width/2);                   // Blue Starting y position
    blueCircle.radius = 25;                                     // Blue Starting radius
    blueCircle.color = BLUE;                                    // COLOR 
    blueCircle.left = blueCircle.x - blueCircle.radius;         // Blue Left Edge 
    blueCircle.right = blueCircle.x + blueCircle.radius;        // Blue Right Edge 
    blueCircle.top = blueCircle.y - blueCircle.radius;          // Blue Top Edge 
    blueCircle.bottom = blueCircle.y + blueCircle.radius;       // Blue Bottom Edge 

    // Orange Circle Structure
    orangeCircle.x = gameWindow.width - 50;                 // Orange Starting x position
    orangeCircle.y = 0;                 // Orange Starting y position
    orangeCircle.radius = 25;                                   // Orange Starting radius
    orangeCircle.color = ORANGE;                                // COLOR 
    orangeCircle.left = orangeCircle.x - orangeCircle.radius;   // Orange Left Edge 
    orangeCircle.right = orangeCircle.x + orangeCircle.radius;  // Orange Right Edge 
    orangeCircle.top = orangeCircle.y - orangeCircle.radius;    // Orange Top Edge 
    orangeCircle.bottom = orangeCircle.y + orangeCircle.radius; // Orange Bottom Edge 


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

    // Orange Circle Directional Movement
    int oDirection = 10;

    bool collision_with_square = 
                        (b_square_y >= blueCircle.top) && 
                        (u_square_y <= blueCircle.bottom) && 
                        (r_square_x >= blueCircle.left) && 
                        (l_square_x <= blueCircle.right);


    // Game Window   
    InitWindow(gameWindow.width, gameWindow.height, "Meteor Falls"); // InitWindow will run for as long as the main() executes
    
    SetTargetFPS(FPS);

    cout << "Start of Window \n";    

    while (!WindowShouldClose())
    {
        // Setup the Drawing 
        BeginDrawing(); 
        ClearBackground(gameWindow.background);


        // Hit Collisions 
        if (collision_with_square)
        {
            DrawText("Game Over", gameWindow.width/5, 200, 100, RED);
        }

        else 
        {
        
            // Update Blue Circle Positions
            blueCircle.left = blueCircle.x - blueCircle.radius;             // Sync Left Edge
            blueCircle.right = blueCircle.x + blueCircle.radius;            // Sync Right Edge
            blueCircle.top = blueCircle.y - blueCircle.radius;              // Sync Top
            blueCircle.bottom = blueCircle.y + blueCircle.radius;           // Sync Bottom

            // Update Orange Circle Positions
            orangeCircle.left = orangeCircle.x - orangeCircle.radius;       // Sync Left Edge
            orangeCircle.right = orangeCircle.x + orangeCircle.radius;      // Sync Right Edge
            orangeCircle.top = orangeCircle.y - orangeCircle.radius;        // Sync Top
            orangeCircle.bottom = orangeCircle.y + orangeCircle.radius;     // Sync Bottom

            // Update Rectangle Position 
            l_square_x = redSquare.x;                                       // Sync Left Edge
            r_square_x = redSquare.x + redSquare.length;                    // Sync Right Edge
            u_square_y = redSquare.y;                                       // Sync Top
            b_square_y = redSquare.y + redSquare.length;                    // Sync Bottom


            // Update Collision with Rectangle  
            collision_with_square = 
                        (b_square_y >= blueCircle.top) && 
                        (u_square_y <= blueCircle.bottom) && 
                        (r_square_x >= blueCircle.left) && 
                        (l_square_x <= blueCircle.right);


            // Create Blue Circle with initial dimensions
            DrawCircle(blueCircle.x,blueCircle.y,blueCircle.radius,blueCircle.color);

            // Create Orange Circle 
            DrawCircle(orangeCircle.x,orangeCircle.y,orangeCircle.radius,orangeCircle.color);


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


            // Control Orange Meteor Movement 
            orangeCircle.y += 8, orangeCircle.x -= 3;

            if ( orangeCircle.y > (gameWindow.height + 300) )
            {
                // Bring orangeCircle back 
                orangeCircle.y = 0;
            }

            if ( orangeCircle.x < -100 )
            {
                orangeCircle.x = gameWindow.width - 25;
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