#include "Game.h"

Game::Game() {}
Game::~Game() {}

void Game::Startscreen(N5110 &lcd, Gamepad &pad)
{
    // Print out the start screen to introduce the game to the player
    lcd.clear();
    lcd.printString("Welcome", 0, 0);
    lcd.refresh();
    wait(1);
    lcd.printString("Press any", 0, 1);
    lcd.printString("Buttons", 0, 2);
    lcd.refresh();
    int op = 0;

    while(op == 0) {
        if(pad.X_pressed() == true) {
            op = 1;
        }

        if(pad.Y_pressed() == true) {
            op = 1;
        }

        if(pad.A_pressed() == true) {
            op = 1;
        }

        if(pad.B_pressed() == true) {
            op = 1;
        }

    }
}

void Game::printControls(N5110 &lcd, Gamepad &pad)
{
    
    // This shows the player how to play the game
    lcd.clear();
    lcd.printString("Controls:", 0, 0);
    lcd.printString("Button control", 0, 1);
    lcd.printString("Right = shoot", 0, 2);
    lcd.printString("Up = jump", 0, 3);
    lcd.printString("Down = down", 0, 4);
    lcd.refresh();
    wait(3);

    // This allows the player to keep reading until they're done and then move on
    while(!pad.A_pressed()) {
        lcd.printString("A to continue", 0, 5);
        lcd.refresh();
    }
}

void Game::setContrast(N5110 &lcd, Gamepad &pad)
{   
    // Lets the player change the contrast to their liking
    lcd.clear();
    lcd.printString("Contrast!",0,0);
    lcd.printString("Change with",0,1);
    lcd.printString("Left pot", 0, 2);
    lcd.printString("A to go", 0, 3);
    lcd.refresh();
    wait_ms(1000);
    
    // Allows the player to keep changing the contrast till they're done
    while(!pad.A_pressed()) {
        lcd.setContrast(pad.read_pot1());
    }
}

void Game::Havefun(N5110 &lcd, Gamepad &pad)
{
    // A nice little send off message
    lcd.clear();
    lcd.printString("You = Circle", 0, 0);
    lcd.refresh();
    wait(1);

    lcd.printString("Hit Cube", 0, 2);
    lcd.refresh();
    wait(1);

    lcd.printString("GO!", 0, 4);
    lcd.refresh();
    wait(1);
}