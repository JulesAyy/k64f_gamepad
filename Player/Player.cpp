#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::init(int hp, int hpMax, int x, int y)
{
    // Initialise all variables to be used in the file
    _hp = hp;
    _hpMax = hpMax;
    _score = 0;
    _x = x;
    _y = y - hpMax;   //Y position depends on the radius of the circle
}

void Player::draw(N5110 &lcd)
{
    // This draws the character as a circle with the black fill as a hp bar
    lcd.drawCircle(_x, _y, _hp, FILL_BLACK);
    // This draws the total hp which will be transparent and the
    lcd.drawCircle(_x, _y, _hpMax, FILL_TRANSPARENT);
}

void Player::update(Gamepad &pad, N5110 &lcd, float mag, Direction d)
{
    int _spd = 5*mag;                           // This sets the sideway movement speed using the X-scale for the joystick
                                                // -----------------------------------------------------------------------
    if(d == E) {                                // This allows the main character to move 
        _x += _spd;                             // --------------------------------------------
    }
    if (d == W) {                            
        _x -= _spd;
    }
    
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
    
    Jump(pad,lcd);
    
    Shoot(pad,lcd);
}

void Player::add_score()
{
    // Simply increment the score by 1 when function is called
    _score++;
}

void Player::hit()
{
    /* Decrement the HP by 1 everytime the player is hit */
    _hp--;
}

/*Vector2D Player::player_pos()
{
    Vector2D pos = { player_x, player_y };
    return pos;
}*/

/* void Player::set_player_pos()
{
    player_x = _x;
    player_y = _y;
} */

void Player::Shoot(Gamepad &pad, N5110 &lcd)
{
        lcd.drawSprite(_x - 6 - 2, _y, 5, 5, (int *)projectile);
        lcd.drawSprite(_x + 6 - 2, _y, 5, 5, (int *)projectile);
}

void Player::Jump(Gamepad &pad, N5110 &lcd)
{
    if(pad.B_pressed()) {
        _y += 9;
    }
    if(pad.X_pressed()) {
        _y -= 9;
    }
}