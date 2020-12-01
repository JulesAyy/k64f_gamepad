/*
* ELEC2645 Embedded Systems Project
* School of Electronic & Electrical Engineering
* University of Leeds
* 2019/20
*
* Name: Jules A. Beszant
* Username: ed17jab
* Student ID Number: 201229356
* Date:03/04/2020
*/

// includes //
#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
#include "Bitmap.h"
#include "Game.h"
#include "Player.h"
#include "Sprite.h"
#include "Cube.h"
#include "Engine.h"
#include <iostream>
#include <cstdlib>

// objects //
N5110 lcd;
Gamepad pad;
Game game;
Engine engine;

// Main functions //
void init();
void intro();
void update();
void render();
void gameOver();

// Variables //

// Main loop //
int main()
{
    init();             // Initialise all classes and variables
    // lcd.drawSprite(0,0,40,84,(int *)gameMap);

#ifdef MENU_TEST
    while(1) {
        intro();
    }
#endif
// Final
    intro();            // Show the game intro to player

    bool Running = true;
    int fps = 20;           // Frames per second

    wait(1.0f/fps);

    while(Running) {

        engine.read_input(pad);
        engine.update(pad,lcd);
        render();
        wait(1.0f/fps);

        if(engine.get_hp() == 0) {
            Running = false;
            gameOver();
        }
    }
}

// Initialise Classes and libraries
void init()
{
    // Initialise the LCD and Gamepad
    lcd.init();

    // lcd.drawSprite(0,0,40,84,(int *)gameMap);
    // lcd.printString("     Test    ",0,1);

    pad.init();
    lcd.setContrast(0.5);

    engine.init(6,2);
}

void intro()
{
    // Brings all the intro to the game to a single functions
    // This makes it more simplier at the main loop

    game.Startscreen(lcd,pad);
    game.printControls(lcd,pad);
    game.setContrast(lcd,pad);
    game.Havefun(lcd,pad);
}

void render()
{
    lcd.clear();
    engine.draw(lcd);
    lcd.refresh();
}

void gameOver()
{
    lcd.clear();
    lcd.printString("GameOver!",0,0);
    lcd.refresh();
}