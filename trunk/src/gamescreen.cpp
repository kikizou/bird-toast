#include "gamescreen.h"


// ----------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------
GameScreen::GameScreen()
{
	setActive( false );
	setVisible( false );
}

GameScreen::~GameScreen()
{
	// Delete Sprites
	for( unsigned int i = 0; i < sprites.size(); i++ )
	{
		if( sprites[i] != NULL )
		{
			delete sprites[i];
		}
	}

	// Clear eventHandlers
	eventHandlers.clear();
}


// ----------------------------------------------------------------------------
// Accessors
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Mutators
// ----------------------------------------------------------------------------
void GameScreen::addSprite( Drawable *sprite )
{
	sprites.push_back( sprite );
}

void GameScreen::addEventHandler( EventHandlerCallback eventHandler )
{
	eventHandlers.push_back( eventHandler );
}


// ----------------------------------------------------------------------------
// Actions
// ----------------------------------------------------------------------------
void GameScreen::handleEvent( SDL_Event *event )
{
	if( this->isActive() )
	{
		for( unsigned int i = 0; i < children.size(); i++ )
		{
			children[i]->handleEvent( event );
		}

		for( unsigned int i = 0; i < eventHandlers.size(); i++ )
		{
			eventHandlers[i]( event, this );
		}
	}
}

void GameScreen::update()
{
	if( this->isActive() )
	{
		// update sprites
		for( unsigned int i = 0; i < sprites.size(); i++ )
		{
			sprites[i]->update();
		}
	}
}

void GameScreen::draw( SDL_Surface *target )
{
	if( this->isVisible() )
	{
		// Draw background
		Animation *background;
		background = this->getAnimation();
		if( background )
			background->draw( target, 0, 0 );
		/*else
		{
			SDL_FillRect( target, NULL, SDL_MapRGB(target->format, 0, 0, 0) );
		}*/

		// Draw sprites
		for( unsigned int i = 0; i < sprites.size(); i++ )
		{
			sprites[i]->draw( target );
		}

		// Draw gui
		for( unsigned int i = 0; i < children.size(); i++ )
		{
			children[i]->draw( target );
		}
	}
}
