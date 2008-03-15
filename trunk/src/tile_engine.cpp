#include "tileengine.h"

//=============================================================================
Tile::Tile()
{
	x = y = 0;
	passable = true;

	imageID = 0;
}

bool Tile::getPassable() { return passable; }

void Tile::setPassable( bool passable ) { this->passable = passable; }
//=============================================================================


TileEngine::TileEngine()
{
	tiles = NULL;

	// view position
	numTilesX = numTilesY = 0;
	tileSize = 64;

	tileX = tileY = 0;
	pxX = pxY = 0;

	velocity.x = velocity.y = 0;
}

TileEngine::TileEngine( int numTilesX, int numTilesY )
{
	tiles = NULL;

	// view position
	setNumTiles( numTilesX, numTilesY );
	tileSize = 64;

	tileX = tileY = 0;
	pxX = pxY = 0;

	velocity.x = velocity.y = 0;
}

TileEngine::TileEngine( int numTilesX, int numTilesY,
						int tileSize )
{
	tiles = NULL;

	// view position
	setNumTiles( numTilesX, numTilesY );
	tileSize = 64;

	tileX = tileY = 0;
	pxX = pxY = 0;

	velocity.x = velocity.y = 0;
}

TileEngine::~TileEngine()
{
	// Delete 2D array of tiles
	for( int i = 0; i < numTilesX; i++ )
		for( int j = 0; j < numTilesY; j++ )
			delete tiles[i][j];	 // Delete allocated object
	
	for( int i = 0; i < numTilesX; i++ )
		delete [] tiles[i];	// Delete *'s
	
	delete[] tiles;	// Delete **'s
	
	// Free images
	for( unsigned int i = 0; i < images.size(); i++ )
	{
		delete images[i];
	}
	
	printf("TileEngine: Successfully Uninitialized.\n");
}

// ----------------------------------------------------------------------------
// Mutators
// ----------------------------------------------------------------------------
int TileEngine::addImage( Imagery *image )
{
	images.push_back( image );
	return (int)images.size()-1;	// New imageID
}

void TileEngine::setNumTiles( int numTilesX, int numTilesY )
{
	if( !tiles )
	{
		this->numTilesX = numTilesX;
		this->numTilesY = numTilesY;

		// Create 2D array of tiles
		tiles = new Tile**[numTilesX];
		for( int i = 0; i < numTilesY; i++ )
			tiles[i] = new Tile*[numTilesY];
		
		// Initialize array of tiles
		for( int i = 0; i < numTilesX; i++ )
			for( int j = 0; j < numTilesY; j++ )
				tiles[i][j] = new Tile();
		
		printf("TileEngine: created 2D array of tiles %ix%i\n", numTilesX, numTilesY);
	}
	else
		printf("warning: TileEngine: Attempting to reset non-dynamic array"); 
}

void TileEngine::setTileSize( int tileSize ) { this->tileSize = tileSize; }

void TileEngine::setVelocity( Vector *v )
{
	velocity = *v;
}


// ----------------------------------------------------------------------------
// Actions
// ----------------------------------------------------------------------------
void TileEngine::update()
{
	pxX += (int)velocity.x;
	pxY += (int)velocity.y;

	while( pxX >= tileSize )
	{
		pxX -= tileSize;
		tileX++;
	}

	while( pxY >= tileSize )
	{
		pxY -= tileSize;
		tileY++;
	}
}

void TileEngine::draw( SDL_Surface *target )
{
	int screenTilesX = target->w / tileSize;
	int screenTilesY = target->h / tileSize;

	for( int i = 0; (i <= screenTilesX) && (i < numTilesX); i++ )
	{
		for( int j = 0; (j <= screenTilesY) && (j < numTilesY); j++ )
		{
			// ID of current tile, (tileX,tileY) being top leftmost
			int imageID = tiles[i+tileX][j+tileY]->imageID;

			// Check for no image in tile
			if( imageID >= 0 )
			{
				images[imageID]->draw( target,
									   i*tileSize - pxX,
									   j*tileSize - pxY );
			}
		}
	}
}
