#ifndef BT_GAMESCREEN_H
#define BT_GAMESCREEN_H
#include <vector>
using namespace std;

#include "gui.h"

//============================================================================
// Class       : Drawable
// Author      : Nate Slottow
// Description : Abstract base unit class to be handled by a GameScreen
//============================================================================
class Drawable
{
public:
	virtual void update() {}
	virtual void draw( SDL_Surface *target ) {}
};

//============================================================================
// Class       : GameScreen
// Author      : Nate Slottow
// Description : Screen or scene for interacting with the game
//				 Top level GUI component in game.
//============================================================================
class GameScreen : public GUIElement
{
public:
	// Constructors
	GameScreen();
	~GameScreen();

	// Mutators
	void addSprite( Drawable *sprite );
	void addEventHandler( EventHandlerCallback eventHandler );

	// Actions
	void handleEvent( SDL_Event *event );

	void update();

	void draw( SDL_Surface *target );

private:
	vector<Drawable *> sprites;		// vector of sprites
	vector<EventHandlerCallback> eventHandlers;
};


#endif
