#ifndef BT_IMAGE_H
#define BT_IMAGE_H
#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <SDL.h>
	#include <SDL_image.h>
#else
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
#endif


//============================================================================
// Class       : Imagery
// Author      : Nate Slottow
// Description : Base abstract drawable class
//============================================================================
class Imagery
{
public:
	virtual void draw( SDL_Surface *target, int x, int y ) {}
};

// ----------------------------------------------------------------------------
// class Image:
// Simple image class that can be easily drawn to a surface (screen)
// ----------------------------------------------------------------------------
class Image : public Imagery
{
public:
	Image();
	Image( const char *filename );
	Image( SDL_Surface *s );
	~Image();

	// Mutators
	void setSurface( const char *filename );
	void setSurface( SDL_Surface *s );
	void setArea( SDL_Rect *a );

	// Accessors
	SDL_Rect getArea();

	// Actions
	void draw( SDL_Surface *target, int x, int y );

private:
	SDL_Surface *surf;
	SDL_Rect area;		// clipped area of surface actually drawn

	friend class Animation;
};


// ----------------------------------------------------------------------------
// class Animation:
// Animation that can be easily drawn to a surface (screen)
// based on equally sized rectangular areas in an image file.
//
// Can loop through any number adjacent rows or columns
// beginning and ending with any specified frames
// (animation can proceed horizontally or vertically)
//
// Top left frame is (0,0)
// One to the right is (1,0)	One from top (0,1)		etc.
// ----------------------------------------------------------------------------
#define ANIM_DEFAULT		0x00
#define ANIM_VERT			0x01
#define ANIM_LOOP			0x04
#define ANIM_LOOP_LASTLINE	0x08


struct AnimationKeys
{
	AnimationKeys();

	int startFrameX, startFrameY;
	int endFrameX, endFrameY;
	Uint32 refreshRate;
	Uint8 flags;
};


class Animation : public Imagery
{
public:
	Animation();

	Animation( const char *filename );

	Animation( Image *image );

	Animation( const char *filename, Uint8 flags );

	Animation( Image *image, Uint8 flags );

	Animation(	const char *filename,
				int numFramesX, int numFramesY, Uint8 flags );

	Animation(	Image *image,
				int numFramesX, int numFramesY, Uint8 flags );

	Animation(	const char *filename,
				int numFramesX, int numFramesY,
				int startFrameX, int startFrameY,
				int endFrameX, int endFrameY,
				Uint8 flags );

	Animation(	Image *image,
				int numFramesX, int numFramesY,
				int startFrameX, int startFrameY,
				int endFrameX, int endFrameY,
				Uint8 flags );

	Animation(	const char *filename,
				int numFramesX, int numFramesY,
				int frameWidth, int frameHeight,
				int startFrameX, int startFrameY,
				int endFrameX, int endFrameY,
				Uint8 flags );

	Animation(	Image *image,
				int numFramesX, int numFramesY,
				int frameWidth, int frameHeight,
				int startFrameX, int startFrameY,
				int endFrameX, int endFrameY,
				Uint8 flags );

	~Animation();
	
	// Accessors
	Image *getImage();
	int getNumFramesX();
	int getNumFramesY();

	// Mutators
	void setImage( const char *filename );
	void setImage( Image *image );

	void setNumFrames( int x, int y );
	void setFrameSize( int w, int h );
	void setStartFrame( int x, int y );
	void setEndFrame( int x, int y );
	void setFlags( Uint8 flags );

	void setCurFrame( int x, int y );

	void setKeys( AnimationKeys *keys );

	void setRefreshRate( Uint32 interval );

	// Actions
	void FreeImage();

	void start();
	void stop();
	void reset();

	void draw( SDL_Surface *target, int x, int y );

private:
	Image *image;

	int numFramesX, numFramesY;
	int startFrameX, startFrameY;
	int endFrameX, endFrameY;			// Inclusive (end frame will show in animation)
	Uint8 flags;						// Direction and loop type

	int curFrameX, curFrameY;

	Uint32 refreshRate;
	SDL_TimerID timer;		// ID and Callback for the SDL_Timer
	friend Uint32 UpdateAnimation( Uint32 interval, void *param );
};

Uint32 UpdateAnimation( Uint32 interval, void *param );


#endif
