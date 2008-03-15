#ifndef BT_TILEENGINE_H
#define BT_TILEENGINE_H
#include "gamescreen.h"
#include "physics.h"

//============================================================================
// Class       : Tile
// Author      : Nate Slottow
// Description : Basic Unit for TileEngine class
//============================================================================
class Tile
{
public:
	Tile();

	bool getPassable();
	void setPassable( bool passable );

	friend class TileEngine;

private:
	int x, y;
	bool passable;

	int imageID;	// ID < 0 means no image
};


//============================================================================
// Class       : BreakableTile
// Author      : Nate Slottow
// Description : Tile than can automatically change passability based on
//				 time or inflicted damage.
//============================================================================
class BreakableTile : public Tile
{
public:
	void reset();		// Unbreak the tile
	
private:
	int initStrength;
	int strength;		// if strength <= 0, tile breaks
};


//============================================================================
// Class       : TileEngine
// Author      : Nate Slottow
// Description : Engine for drawing world to screen using square tiles and
// 				 parallax background scrolling.
//============================================================================
class TileEngine : public Drawable
{
public:
	TileEngine();
	TileEngine( int numTilesX, int numTilesY );	// Default tileSize of 64px
	TileEngine( int numTilesX, int numTilesY,
				int tileSize );

	~TileEngine();

	// Mutators
	int addImage( Imagery *image );		// Returns imageID of added image

	void setNumTiles( int numTilesX, int numTilesY );
	void setTileSize( int tileSize );

	void setVelocity( Vector *v );

	// Actions
	void update();
	void draw( SDL_Surface *target );

private:
	Tile ***tiles;

	vector<Imagery *> images;

	// View position
	int numTilesX, numTilesY;	// Number of tiles in array
	int tileSize;				// Default = 64x64

	int tileX, tileY;			// top left most tile on screen
	int pxX, pxY;				// pixel offset from top left of tile
 
	Vector velocity;
};

#endif
