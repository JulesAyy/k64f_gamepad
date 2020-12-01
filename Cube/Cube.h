#ifndef CUBE_H
#define CUBE_H

/*****************************/
#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"
#include "Struct.h"
#include "Player.h"
/*****************************/

/* Including this to allow random number generator */
#include <cstdlib>
#include <iostream>

/** Cube Class
* @brief Create enemie class called Cubes
* @author Jules A. Beszant
* @date May, 2020
*/

class Cube
{

public:

    /** Constructor */
    Cube();

    /** Destructor */
    ~Cube();

    /** Initialise the class */
    void init(int cube_x, int cube_y);

    /** Draw the Cube enemy
    * @brief uses the LCD to draw the Cube
    */
    void draw(N5110 &lcd);

    /** Update the cubes movement
    * @brief Move the cube based on the player Coords
    */
    void update(int player_posx, int player_posy);
    
    
    /** Moves the cube back to spawn once it hits a player
    */
    void hit();

    /** Get the Cube position
    * @return The Cube position in a struct with .x and .y
    */
    Vector2D cube_pos();

    /** Sets the Cube position
    * @param Vector2D cube_pos @details Cube position in X and Y
    */
    void set_cube_pos(Vector2D cube_pos);

    /** Variables in Cube Class
    * @param cube_x @details Cube X Coord
    * @param cube_y @details Cube Y Coord
    * @param cube_size @details sets the size of the cube
    */
    int cube_x;
    int cube_y;
    int cube_size;

    /** Player Coords for the Cube Class
    * @param playerX @details Gets the Player X coord
    * @param playerY @details Gets the Player Y coord
    */
    int playerX;
    int playerY;
    
    /** Player Coords struct
    * @brief This is for the player Coords used in the Class
    */
    Player_pos player_pos;
    
    /** cube Coords for the Cube Class
    * @param _x @details Gets the cube X coord
    * @param _y @details Gets the cube Y coord
    */
    int _x;
    int _y;
};

#endif