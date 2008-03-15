#include "image.h"

/*
 * AnimationKeys
 */
AnimationKeys::AnimationKeys()
{
	startFrameX = 0;
	startFrameY = 0;
	endFrameX = 0;
	endFrameY = 0;

	refreshRate = 100;

	flags = ANIM_DEFAULT;
}

// ----------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------
Animation::Animation()
{
	image = NULL;

	setNumFrames( 0, 0 );

	setStartFrame( 0, 0 );
	setEndFrame( 0, 0 );

	setFlags( ANIM_DEFAULT );

	setCurFrame( 0, 0 );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation( const char *filename )
{
	image = NULL;
	setImage( filename );

	setNumFrames( 0, 0 );

	setStartFrame( 0, 0 );
	setEndFrame( 0, 0 );

	setFlags( ANIM_DEFAULT );

	setCurFrame( 0, 0 );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation( Image *image )
{
	image = NULL;
	setImage( image );

	setNumFrames( 0, 0 );

	setStartFrame( 0, 0 );
	setEndFrame( 0, 0 );

	setFlags( flags );

	setCurFrame( 0, 0 );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation( const char *filename, Uint8 flags )
{
	image = NULL;
	setImage( filename );

	setNumFrames( 0, 0 );

	setStartFrame( 0, 0 );
	setEndFrame( 0, 0 );

	setFlags( flags );

	setCurFrame( 0, 0 );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation( Image *image, Uint8 flags )
{
	image = NULL;
	setImage( image );

	setNumFrames( numFramesX, numFramesY );

	setStartFrame( 0, 0 );
	setEndFrame( numFramesX-1, numFramesY-1 );

	setFlags( flags );

	setCurFrame( 0, 0 );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation(	const char *filename,
						int numFramesX, int numFramesY, Uint8 flags )
{
	image = NULL;
	setImage( filename );

	setNumFrames( numFramesX, numFramesY );
	
	if( image->surf )
	{
		SDL_Rect area;
		area.x = 0;
		area.y = 0;
		area.w = image->surf->w / numFramesX;
		area.h = image->surf->h / numFramesY;
		image->setArea( &area );
	}

	setStartFrame( 0, 0 );
	setEndFrame( numFramesX-1, numFramesY-1 );

	setFlags( flags );

	setCurFrame( 0, 0 );

	setRefreshRate( 100 );
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation(	Image *image,
						int numFramesX, int numFramesY, Uint8 flags )
{
	image = NULL;
	setImage( image );

	setNumFrames( numFramesX, numFramesY );
	
	if( image->surf )
	{
		SDL_Rect area;
		area.x = 0;
		area.y = 0;
		area.w = image->surf->w / numFramesX;
		area.h = image->surf->h / numFramesY;
		image->setArea( &area );
	}

	setStartFrame( 0, 0 );
	setEndFrame( numFramesX-1, numFramesY-1 );

	setFlags( flags );

	setCurFrame( 0, 0 );

	setRefreshRate( 100 );
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation(	const char *filename,
						int numFramesX, int numFramesY,
						int startFrameX, int startFrameY,
						int endFrameX, int endFrameY,
						Uint8 flags )
{
	image = NULL;
	setImage( filename );

	setNumFrames( numFramesX, numFramesY );
	
	if( image->surf )
	{
		SDL_Rect area;
		area.x = 0;
		area.y = 0;
		area.w = image->surf->w / numFramesX;
		area.h = image->surf->h / numFramesY;
		image->setArea( &area );
	}

	setStartFrame( startFrameX, startFrameY );
	setEndFrame( endFrameX, endFrameY );

	setFlags( flags );

	setCurFrame( startFrameX, startFrameY );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation(	Image *image,
						int numFramesX, int numFramesY,
						int startFrameX, int startFrameY,
						int endFrameX, int endFrameY,
						Uint8 flags )
{
	image = NULL;
	setImage( image );

	setNumFrames( numFramesX, numFramesY );
	
	if( image->surf )
	{
		SDL_Rect area;
		area.x = 0;
		area.y = 0;
		area.w = image->surf->w / numFramesX;
		area.h = image->surf->h / numFramesY;
		image->setArea( &area );
	}

	setStartFrame( startFrameX, startFrameY );
	setEndFrame( endFrameX, endFrameY );

	setFlags( flags );

	setCurFrame( startFrameX, startFrameY );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation(	const char *filename,
						int numFramesX, int numFramesY,
						int frameWidth, int frameHeight,
						int startFrameX, int startFrameY,
						int endFrameX, int endFrameY,
						Uint8 flags )
{
	image = NULL;
	setImage( filename );

	setNumFrames( numFramesX, numFramesY );
	
	if( image->surf )
	{
		SDL_Rect area;
		area.x = 0;
		area.y = 0;
		area.w = frameWidth;
		area.h = frameHeight;
		image->setArea( &area );
	}

	setStartFrame( startFrameX, startFrameY );
	setEndFrame( endFrameX, endFrameY );

	setFlags( flags );

	setCurFrame( startFrameX, startFrameY );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}

Animation::Animation(	Image *image,
						int numFramesX, int numFramesY,
						int frameWidth, int frameHeight,
						int startFrameX, int startFrameY,
						int endFrameX, int endFrameY,
						Uint8 flags )
{
	image = NULL;
	setImage( image );

	setNumFrames( numFramesX, numFramesY );
	
	if( image->surf )
	{
		SDL_Rect area;
		area.x = 0;
		area.y = 0;
		area.w = frameWidth;
		area.h = frameHeight;
		image->setArea( &area );
	}

	setStartFrame( startFrameX, startFrameY );
	setEndFrame( endFrameX, endFrameY );

	setFlags( flags );

	setCurFrame( startFrameX, startFrameY );

	refreshRate = 100;
	timer = NULL;

	// Set the animation
	reset();
}


Animation::~Animation()
{
	stop();
}


// ----------------------------------------------------------------------------
// Accessors
// ----------------------------------------------------------------------------
Image *Animation::getImage() { return image; }

int Animation::getNumFramesX() { return numFramesX; }

int Animation::getNumFramesY() { return numFramesY; }


// ----------------------------------------------------------------------------
// Mutators
// ----------------------------------------------------------------------------
void Animation::setImage( const char *filename )
{
	if( !image )
		image = new Image( filename );
}

void Animation::setImage( Image *image )
{
	this->image = image;
}

void Animation::setNumFrames( int x, int y )
{
	numFramesX = x;
	numFramesY = y;
}

void Animation::setFrameSize( int w, int h )
{
	image->area.w = w;
	image->area.h = h;
}

void Animation::setStartFrame( int x, int y )
{
	startFrameX = x;
	startFrameY = y;
}

void Animation::setEndFrame( int x, int y )
{
	endFrameX = x;
	endFrameY = y;
}

void Animation::setFlags( Uint8 flags ) { this->flags = flags; }

void Animation::setCurFrame( int x, int y )
{
	if( (x >= startFrameX) && (x <= endFrameX) &&
		(y >= startFrameY) && (y <= endFrameY) )
	{
		curFrameX = x;
		curFrameY = y;
	}
	else
	{
		curFrameX = startFrameX;
		curFrameY = startFrameY;
	}
}

void Animation::setKeys( AnimationKeys *keys )
{
	setStartFrame( keys->startFrameX, keys->startFrameY );

	setEndFrame( keys->endFrameX, keys->endFrameY );

	setFlags( keys->flags );
}

void Animation::setRefreshRate( Uint32 interval ) {	refreshRate = interval; }


// ----------------------------------------------------------------------------
// Actions
// ----------------------------------------------------------------------------
void Animation::FreeImage()
{
	if( image != NULL )
		delete image;
}

void Animation::start()
{
	// Check if already running
	if( timer != NULL )
		stop();

	timer = SDL_AddTimer( refreshRate, &UpdateAnimation, this );
}

void Animation::stop()
{
	// Check if already running
	if( timer != NULL )
	{
		SDL_RemoveTimer( timer );
		timer = NULL;
	}
}

void Animation::reset()
{
	setCurFrame( startFrameX, startFrameY );

	// Set the area rect to the right frame
	image->area.x = curFrameX * image->area.w;
	image->area.y = curFrameY * image->area.h;
}

void Animation::draw( SDL_Surface *target, int x, int y )
{
	image->draw( target, x, y );
}


/*
 * Callback for frame update timer
 */
Uint32 UpdateAnimation( Uint32 interval, void *param )
{
	
	Animation *anim = (Animation *)param;
	
	if( (anim->flags & ANIM_VERT) > 0 )
	{	// Move Vertically
		anim->curFrameY++;
		
		if( anim->curFrameY > anim->endFrameY )
		{
			if( anim->curFrameX == anim->endFrameX )
			{	// We've passed the end of the animation
				if( (anim->flags >> 2) > 0 )
				{	// We're Looping
					if( (anim->flags & ANIM_LOOP_LASTLINE) )
						anim->curFrameY = 0;
					else
					{
						anim->reset();
					}
				}
				else
				{	// We're NOT Looping
					anim->reset();
					return 0;	// discontinue timer
				}
			}
			else
				anim->curFrameX++;	// To next column
		}
	}
	else
	{	// Move Horizontally
		anim->curFrameX++;

		if ( anim->curFrameX > anim->endFrameX )
		{
			if( anim->curFrameY == anim->endFrameY )
			{	// We've passed the end of the animation
				if( (anim->flags >> 2) > 0 )
				{	// We're Looping
					if( (anim->flags & ANIM_LOOP_LASTLINE) )
						anim->curFrameX = 0;
					else
					{
						anim->reset();
					}
				}
				else
				{	// We're NOT Looping
					anim->reset();
					return 0;	// discontinue timer
				}
			}
			else
				anim->curFrameY++;	// To next row
		}
	}

	// Set the area rect to the right frame
	Image *image = anim->getImage();
	SDL_Rect area = image->getArea();

	area.x = anim->curFrameX * area.w;
	area.y = anim->curFrameY * area.h;

	image->setArea( &area );

	return interval;
}
