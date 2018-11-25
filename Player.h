#ifndef PLAYER_H
#define PLAYER_H

#include "Hitbox.h"
#include "Vector.h"
#include "Trail.h"
#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>

#define PLAYER_LENGTH 25 // 2.5 meters
#define PLAYER_WIDTH 7 // .7 meter
#define PLAYER_HEIGHT 10 // 1 meter

#define MOVE_RATE 100 // divides the movement by move_rate value, essentially move_rate 
						// is how many ticks for the model to move forward 1 unit
#define TILT_RATE 2 // how quickly the model tilts while a turn key is pressed. radians per second
#define MAX_TILT .52 // max radians that the model can tilt while turning
#define TURN_RATE 3 // rate of which the bike turns per tick. radians per tick

class Player {
private:
	Vector * loc; // location of the player
	Vector * direction; // vector that is the direction that the bike is pointed
	Vector * up_vector; // vector pointing up from the player
	Vector * tilt_vector; // vector determining the tilt
	double angle; // angle of the player's tilt
	int turn; // int that represents how the player is turning. -1 for left, 1 for right, and 0 for going straight
	double velocity; // velocity of the player as a number
	bool trail_on;
	Trail *trail;
	Hitbox * hitbox;

	bool left, right, alive;

public:
	// default constructor
	Player();

	// constructor for the player
	Player(double loc_x, double loc_y, double loc_z, double dir_x, double dir_y, double dir_z);
	

	// destructor for the player
	~Player();

	// turns on the trail of the bike. Once turned on, cannot be turned off
	void beginTrail( bool limit );

	// move the player in the current direction it is pointed based on its velocity
	void movePlayer( double dt );

	// do all the opengl to render the model for the player model. will call the trail render through this
	void display();

	Trail* getTrail();

	Vector * getLocation();
	Vector* getTrailBottom();
	Vector* getTrailTop();

	Hitbox * getHitbox();

	void keyPressed(SDL_Event event);
	void keyReleased(SDL_Event event);

	void setAlive( bool newVal );
	void setLeft( bool newVal );
	void setRight( bool newVal );

	// Get camera position
	Vector getViewLocation();
};
#endif