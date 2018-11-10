#ifndef HITBOX_H
#define HITBOX_H

#include "Vector.h"
#include "Matrix.h"

// Position Indicators : Top/Bottom - Front/Back - Left/Right
#define BBL 0
#define BBR 1
#define BFR 2
#define BFL 3
#define TBL 4
#define TBR 5
#define TFR 6
#define TFL 7


class Hitbox {
private:
	Vector pos, forward, up;
	double width, length, height; // width: side/side, length: forward/back

	Vector points[8]; // To calculate in constructor

public:
	Hitbox( Vector p, Vector f, Vector u, double w, double l, double h );

	Vector getPos();
	Vector getForward();
	Vector getUp();
	double getWidth();
	double getLength();
	double getHeight();
	Vector getPoint(int i);

	void setPos( Vector toSet );
	void setForward( Vector toSet );
	void setUp( Vector toSet );
	void setWidth( double toSet );
	void setLength( double toSet );
	void setHeight( double toSet );

	friend bool testCollision( Hitbox h1, Hitbox h2 );
};

int main();

#endif
