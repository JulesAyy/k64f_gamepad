#include "Cube.h"

Cube::Cube() {}
Cube::~Cube() {}

void Cube::init(int cube_x, int cube_y)
{
    /* This allows the speed to be inversly propertional to the size */
    cube_size = 6;
    
    _x = cube_x;
    _y = cube_y;
}

void Cube::draw(N5110 &lcd)
{
    lcd.drawRect(_x, _y, cube_size, cube_size, FILL_BLACK);
}

void Cube::update(int player_posx, int player_posy)
{
    if(_x > player_posx) {                 // Moves the cube based on player coords
        _x -= 1;                           // If player is to the left the cube will move left
    }
    if(_x < player_posx) {                                // If player is on the right the cube will move right
        _x += 1;
    }
    
    if((_y - player_posy) >= 0) {
        _y -= 9;
                               // This allows the cube to jump from one platform to another
    }
    if((_y - player_posy) <= -6) {
        _y += 9;
                               // A wait is implemented to stop it from completely mimicing the player
    }
    
    /* These make sure the cube doesn't go out of boundries */
    if(_x >= 83) {
        _x = 83;
    }
    if(_x <= 1) {
        _x = 1;
        }
    if(_y >= 47) {
        _y = 40;
    }
    if(_y <= 1) {
        _y = 4;
        }
    
    // #ifndef CUBE_COORD
    
    // printf("X Coord = %d", _x);
    // printf("\nY Coord = %d", _y);
    
    // #endif
}

void Cube::hit()
{
    _x = cube_x;
    _y = cube_y;   
}

/* Vector2D Cube::cube_pos()
{
    Vector2D cpos = { cube_x, cube_y };     // Retrieves the cube coords
    return cpos;
}

void Cube::set_cube_pos(Vector2D cpos)
{
    cube_x = cpos.x;
    cube_y = cpos.y;
} */