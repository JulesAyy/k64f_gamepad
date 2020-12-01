#ifndef ENGINE_H
#define ENGINE_H

/*****************************/
#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Player.h"
#include "Cube.h"
#include "Sprite.h"
#include "Struct.h"
#include <string>
#include <iostream>
#include <sstream>
/*****************************/

/** Engine Class
* @brief Engine Class to run the game
* @author Jules A. Beszant
* @date May, 2020
*/

class Engine
{

public:

    /** Constructor */
    Engine();

    /** Destructor */
    ~Engine();

    /** Initial Variable used in Game
    * @param hp (int) @details the players HP
    * @param spd (int) @details Players movement spd
    */
    void init(int hp, int spd);

    /** Reads the input of the gamepad
    */
    void read_input(Gamepad &pad);

    /** Update game based on player position and gamepad input
    */
    void update(Gamepad &pad, N5110 &lcd);

    /** Draws the objects
    */
    void draw(N5110 &lcd);
    
    /** Prints out the score and player HP
    * @brief the score and hp will be printed out onto the lcd screen
    */
    void print_score(N5110 &lcd);
    
    /** Player HP
    * @return player HP
    */
    int _hp;
    
    int get_hp() const
    {
        return this->player.get_hp();
    };
    
    /** Player Coords struct
    * @brief This is for the player Coords used in the Class
    */
    Player_pos player_pos;
    
    /** Cube Coords struct
    * @brief This is for the cube Coords used in the Class
    */
    Cube_pos cube_pos;
    
    /** Objects for player and cube
    * @brief Objects are created to use in engine class
    */
    Player player;
    Cube cube;
    
    /** Gets the direction and magnitude of the Joystick
    * @return Direction in N,NE,E,SE,S,SW,W,NW and mag from 0 to 1
    */
    Direction _d;
    float _mag;

private:

    /* Collision check */
    void Check_Collision(Gamepad &pad, N5110 &lcd);
    void Check_p1_Collision(Gamepad &pad);

    /* Player stats */
    int _spd;

    /* Player X-coord, Y is not needed as this is for side movement */
    float _p1x;
    float _p1y;
};

#endif