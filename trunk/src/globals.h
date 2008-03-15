#ifndef BT_GLOBALS_H
#define BT_GLOBALS_H
#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <SDL.h>
	#include <SDL_image.h>
#else
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
#endif
#include "gamescreen.h"

// ----------------------------------------------------------------------------
// Program
// ----------------------------------------------------------------------------
void InitGame();
void InitMainLoop();
void Cleanup();

int UpdateNetwork( void *data );

SDL_Thread *g_networkThread;

bool g_running = true;

// ----------------------------------------------------------------------------
// Video
// ----------------------------------------------------------------------------
SDL_Surface *g_windowSurface;
unsigned int g_winWidth = 1024;
unsigned int g_winHeight = 768;
unsigned int g_winBpp = 32;
Uint32 g_winFlags = SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_ANYFORMAT;

unsigned int g_refreshRate = 20;


// ----------------------------------------------------------------------------
// Game
// ----------------------------------------------------------------------------
GameScreen *g_curScreen;
/*
void ChangeActiveScreen( GameScreen *screen )
{
	g_curScreen->setActive( false );
	g_curScreen = screen;
	g_curScreen->setActive( true );
	g_curScreen->setVisible( true );
}
*/

#endif
