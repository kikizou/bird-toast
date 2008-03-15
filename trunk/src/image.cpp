#include "image.h"

// ----------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------
Image::Image()
{
	area.x = 0;
	area.y = 0;
	area.w = 0;
	area.h = 0;

	surf = NULL;
}

Image::Image( const char *filename )
{
	// Load image from file -> surface
	surf = IMG_Load( filename );

	area.x = 0;
	area.y = 0;

	if( !surf )
		printf( "Couldn't load image: %s\n", filename );
	else
	{
		area.w = surf->w;
		area.h = surf->h;
	}
}

Image::Image( SDL_Surface *s )
{
	surf = s;
	area.x = 0;
	area.y = 0;
	area.w = surf->w;
	area.h = surf->h;
}

Image::~Image()
{
	if( surf != NULL )
	{
		SDL_FreeSurface( surf );
		surf = NULL;
	}
}


// ----------------------------------------------------------------------------
// Mutators
// ----------------------------------------------------------------------------
void Image::setSurface( const char *filename )
{
	// Check if surf has data, and free if necessary
	if( surf != NULL )
		SDL_FreeSurface( surf );

	// Load image from file -> surface
	surf = IMG_Load( filename );
}

void Image::setSurface( SDL_Surface *s )
{
	// Check if surf has data, and free if necessary
	if( surf != NULL )
		SDL_FreeSurface( surf );

	// Set to new surface
	surf = s;
}

void Image::setArea( SDL_Rect *a )
{
	area.x = a->x;
	area.y = a->y;
	area.w = a->w;
	area.h = a->h;
}


// ----------------------------------------------------------------------------
// Accessors
// ----------------------------------------------------------------------------
SDL_Rect Image::getArea()
{
	return area;
}


// ----------------------------------------------------------------------------
// Actions
// ----------------------------------------------------------------------------
void Image::draw( SDL_Surface *target, int x, int y )
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;

	if( surf )
		SDL_BlitSurface( surf, &area, target, &dst );
	else
	{
		dst.w = area.w;
		dst.h = area.h;
		SDL_FillRect( target, &dst, SDL_MapRGB(target->format, 255, 0, 0) );
	}
}
