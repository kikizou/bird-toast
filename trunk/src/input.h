#ifndef BT_INPUT_H
#define BT_INPUT_H
#ifdef WIN32
	#include <SDL.h>
#else
	#include <SDL/SDL.h>
#endif

/*
 * EventHandlerCallback
 */
typedef void (*EventHandlerCallback)( SDL_Event *event, void *fakeThis );


#endif
