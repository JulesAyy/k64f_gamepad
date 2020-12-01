#ifndef GAME_H
#define GAME_H

/*****************************/
#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
/*****************************/

/** Game Class
* @brief Initial game screen, main menu and introduction
* @author Jules A. Beszant
* @date May, 2020
*/

class Game
{

public:

    /** Constructor */
    Game();

    /** Destructor */
    ~Game();

    /** Start screen to show the game introductions
    * @brief Shows the start screen
    */

    void Startscreen(N5110 &lcd, Gamepad &pad);

    /** Print out the controls to show player how to play
    * @brief Print out the controls to lcd screen
    */
    void printControls(N5110 &lcd, Gamepad &pad);

    /** Sets the contrast to the players liking
    * @brief Let the player set the contrast of the game
    */
    void setContrast(N5110 &lcd, Gamepad &pad);

    /** Have fun
    * @brief tells the player to have fun
    */
    void Havefun(N5110 &lcd, Gamepad &pad);

};

#endif