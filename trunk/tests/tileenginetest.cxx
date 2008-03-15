#include "globals.h"
#include "image.h"
#include "tileengine.h"

TileEngine *engine;

/*
 * InitGame: Initialize global interfaces and create game threads
 */
void InitGame()
{
	// Initialize SDL
	if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) < 0 )
	{
		printf( "Could not initialize SDL: %s\n", SDL_GetError() );
		exit( 0 );
	}
	
	// Initialize the window
	SDL_WM_SetCaption( "Bird Toast", NULL );

	g_windowSurface = SDL_SetVideoMode( g_winWidth, g_winHeight, g_winBpp, g_winFlags );

	if( !g_windowSurface )
	{
		printf(  "Could not set video mode!\n" );
		exit( 0 );
	}

	// Initialize GameScreens

	// TODO: Initialize the physics thread
	// TODO: Initialize the network thread
}


/*
 * Cleanup: Free all memory, uninitialize everything
 */
void Cleanup()
{
	// TODO: Stop running threads?
	delete engine;
	
	SDL_FreeSurface( g_windowSurface );		// Free the main video surface
	SDL_Quit();								// Cleanup SDL
}


/*
 * InitMainLoop: Handle events and render
 */
void InitMainLoop()
{
	while( g_running )
	{
		// Main event loop
		SDL_PumpEvents();
		SDL_Event event;
		while( SDL_PollEvent(&event) )
		{
			// TODO: Update current event handlers

			// Top level check for general program actions
			switch( event.type )
			{
			case SDL_KEYDOWN:
				switch( event.key.keysym.sym )
				{
				case SDLK_F12:			// Action: Quit
					g_running = false;	// Stop other threads from running
					return;				// Stop thread

				case SDLK_F11:			// Action: Toggle Fullscreen
					if( (g_winFlags & SDL_FULLSCREEN) > 0 )
					{
						SDL_FreeSurface( g_windowSurface );
						g_winFlags = SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_ANYFORMAT;
						g_windowSurface = SDL_SetVideoMode( g_winWidth, g_winHeight, g_winBpp, g_winFlags );
					}
					else
					{
						SDL_FreeSurface( g_windowSurface );
						g_winFlags = SDL_HWSURFACE|SDL_FULLSCREEN|SDL_DOUBLEBUF|SDL_ANYFORMAT;
						g_windowSurface = SDL_SetVideoMode( g_winWidth, g_winHeight, g_winBpp, g_winFlags );
					}
					break;
					
				case SDLK_RIGHT:
					printf("Keypress\n");
					Vector v;
					v.x = 1.0f;
					engine->setVelocity( &v );
					break;
				}
				break;

			case SDL_QUIT:			// Action: Quit
				g_running = false;	// Stop other threads from running
				return;				// Stop thread
			}
		}
		
		engine->update();
		engine->draw( g_windowSurface );

		// Draw screen
		SDL_Flip( g_windowSurface );

		SDL_Delay( g_refreshRate );
	}
}


/*
 * ENTRY POINT
 */
int main( int argc, char *argv[] )
{
	// TODO: Handle runtime flags

	InitGame();

	Animation *test = new Animation( "../tiles/straight.png" );
	engine = new TileEngine( 10, 10 );
	engine->addImage( test );
	
	InitMainLoop();

	// TODO: Wait for threads to quit before ending program

	Cleanup();

	return 0;
}
