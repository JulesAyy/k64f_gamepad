#include "Engine.h"

Engine::Engine() {}
Engine::~Engine() {}

void Engine::init(int hp, int spd)
{
    // Initialise player stats here, can be changed to get different gameplay
    // player.init(HP,HP MAX, X-coord, Y-coord)
    player.init(4,4,69,27);
    
    // Initialise Cube
    cube.init(1,1);

    // initialise variables
    _hp = hp;
    _spd = spd;
    
    // player_pos.x = player._x;
    // player_pos.y = player._y;
    
    // cube_pos.x = cube.cube_x;
    // cube_pos.y = cube.cube_y;
}

void Engine::read_input(Gamepad &pad)
{
    // Reads the gamepad input
    _p1x = pad.get_coord().x;
    _p1y = pad.get_coord().y;
    
    _d = pad.get_direction();
    _mag = pad.get_mag();
}

void Engine::update(Gamepad &pad, N5110 &lcd)
{
    // Updates the Coord for both the cube and player
    player_pos.x = player._x;
    player_pos.y = player._y;
    
    cube_pos.x = cube._x;
    cube_pos.y = cube._y;
    
    // Update the gameplay
    player.update(pad,lcd,_mag,_d);
    cube.update(player_pos.x,player_pos.y);
    
    /* Check for wall and player collision */
    Check_Collision(pad,lcd);
    Check_p1_Collision(pad);
    
    printf("Player_pos.x = %d", player_pos.x);
    printf("\n\rPlayer_pos.y = %d", player_pos.y);
    
    printf("\n\rCube_pos.x = %d", cube_pos.x);
    printf("\n\rCube_pos.y = %d", cube_pos.y);
}

void Engine::draw(N5110 &lcd)
{
    /* Draw out the player and enemies */
    lcd.drawSprite(0,0,40,84,(int *)gameMap);
    player.draw(lcd);
    cube.draw(lcd);
    
    /* Print out score */
    print_score(lcd);

}

void Engine::Check_Collision(Gamepad &pad, N5110 &lcd)
{
    if(pad.A_pressed()) {
        player.Shoot(pad,lcd);
        lcd.refresh();
        if((cube_pos.x - player_pos.x <= 15 ) && (player_pos.x - cube_pos.x <= 15) && (player_pos.y - cube_pos.y <= 15) && (player_pos.y - cube_pos.y <= 15))
            player.add_score();
    }   // This adds a score everytime the cube is hit
}

void Engine::Check_p1_Collision(Gamepad &pad)
{
    // bool Collision = false;
    
    int cube_middle_coord_x = cube_pos.x + 3;
    int cube_middle_coord_y = cube_pos.y + 3;
    
    int player_middle_coord_x = player_pos.x + 2;
    int player_middle_coord_y = player_pos.y + 2;
    
    // Checks if the cube is too close to the player
    if(((cube_middle_coord_x - player_middle_coord_x <= 6 ) && (cube_middle_coord_x - player_middle_coord_x >= -6)) && ((cube_middle_coord_y - player_middle_coord_y <= 6) && (cube_middle_coord_y - player_middle_coord_y >= -6))) {
        // Collision = true;
        _hp--;
        player.hit();
        cube.hit();
        
    // Player will lose hp if the cube is too close to it
    // The cube will then teleport to a location away from player if the player gets it
    // The player will then have to start with a lower health
    cube.cube_x = 15;
    cube.cube_y = 9 - cube.cube_size;
    }

    // This simply gives the player an invulnerability period so they wont lose too much health
    /* if(Collision) {
        wait(1);
        Collision = false;
    } */
}

// This prints out the score and hp
void Engine::print_score(N5110 &lcd)
{
    int player_score = player.get_score();
    
    char buffer1[14];
    sprintf(buffer1,"%d",player_score);
    char buffer2[14];
    sprintf(buffer2,"%d",_hp);
    
    lcd.printString(buffer1,20,1);
    lcd.printString(buffer2,4,1);
}