
#ifndef Player_H
#define Player_H

/*****************************/
#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Sprite.h"
/*****************************/

/** Player Class
* @brief Player stats, control and gameplay
* @author Jules A. Beszant
* @date May, 2020
*/

class Player
{

public:

    /** Constructor */
    Player();

    /** Destructor */
    ~Player();


    /** Initialise player stats
    * @param hp (int) @details Players current HP
    * @param hpMax(int) @details Players Max hp
    * @param x (int) @details Players starting X coord
    * @param y (int) @details Players starting Y coord
    */
    void init(int hp, int hpMax, int x, int y);

    /** Draw the player on the LCD
    * @brief Draws the player sprite to the screen
    */
    void draw(N5110 &lcd);

    /** Update player based on gamepad feedback
    * @brief updates the gameplay from the gamepad input
    */
    void update(Gamepad &pad, N5110 &lcd, float mag, Direction d);

    /** Increment player score by 1 when called
    * @brief Add score for the player
    */
    void add_score();

    /** Decrement player hp by 1 when called
    * @brief The player gets hit, call this function to reduce hp
    */
    void hit();

    /** Sets the player position based on previous position
    */
    void set_player_pos();
    
    /** Allows the player to shoot projectiles
    * @brief When A is held the projectile appears on both side
    */
    void Shoot(Gamepad &pad, N5110 &lcd);
    
    /** Allows the player to jump
    * @param X button @details Jump up
    * @param Y button @details Jump down
    */
    void Jump(Gamepad &pad, N5110 &lcd);

    /** Return player score
    * @return current score
    */
    int get_score() const
    {
        return this->_score;
    };

    /** Return HP when called
    * @return player hp
    */
    int get_hp() const
    {
        return this->_hp;
    };

    /** Return SPD when called
    * @return player spd
    */
    int get_spd() const
    {
        return this->_spd;
    };

    /** Player Position
    * @param _x @details Player X coord
    * @param _y @details Player Y coord
    */
    int _x;
    int _y;


private:

    // int _x;
    // int _y;
    int _hp;
    int _hpMax;
    float _spd;
    int _score;


};

#endif