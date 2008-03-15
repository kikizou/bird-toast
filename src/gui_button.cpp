#include "gui.h"


// ----------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------
GUIButton::GUIButton()
{
	hover = false;
	press = false;
	click = false;
}

GUIButton::~GUIButton()
{
}

// ----------------------------------------------------------------------------
// Actions
// ----------------------------------------------------------------------------
void GUIButton::handleEvent( SDL_Event *event )
{
	if( active )
	{
		Animation *anim = getAnimation();
		SDL_Rect pos = getPosition();
		SDL_Rect parentPos;

		if( parent != NULL )
			parentPos = parent->getPosition();
		else
		{
			parentPos.x = 0;
			parentPos.y = 0;
			parentPos.w = 0;
			parentPos.h = 0;
		}

		switch( event->type )
		{
		// Check for hover
		case SDL_MOUSEMOTION:
			if( (event->motion.x >= (pos.x + parentPos.x)) &&
				(event->motion.x <= (pos.x + parentPos.x + pos.w)) &&
				(event->motion.y >= (pos.y + parentPos.y)) &&
				(event->motion.y <= (pos.y + parentPos.y + pos.h)) )
			{	// Mouse is in the button area
				if( !press && !click && !hover )
				{
					hover = true;
					// hover animation
					anim->setStartFrame( 0, 1 );
					anim->setEndFrame( anim->getNumFramesX(), 1 );
					anim->reset();
				}
			}
			else if ( hover )
			{	// Mouse not in the button area but was previously
				hover = false;
				click = false;

				// End hovering animation
				if( focused )
				{	// focused animation
					anim->setStartFrame( 0, 2 );
					anim->setEndFrame( anim->getNumFramesX(), 2 );
					anim->reset();
				}
				else
				{	// normal animation
					anim->setStartFrame( 0, 0 );
					anim->setEndFrame( anim->getNumFramesX(), 0 );
					anim->reset();
				}
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			if( hover )
			{
				press = true;
				focused = true;

				// press animation
				anim->setStartFrame( 0, 3 );
				anim->setEndFrame( anim->getNumFramesX(), 3 );
				anim->reset();
			}
			else
			{
				focused = false;

				// normal animation
				anim->setStartFrame( 0, 0 );
				anim->setEndFrame( anim->getNumFramesX(), 0 );
				anim->reset();
			}

			break;

		case SDL_MOUSEBUTTONUP:
			// Check for click and do action
			if( press )
			{
				press = false;

				// focused animation
				anim->setStartFrame( 0, 2 );
				anim->setEndFrame( anim->getNumFramesX(), 2 );
				anim->reset();

				if( hover )
				{
					click = true;
					if( eventHandler != NULL )
						eventHandler( event, this );	// CLICK! call the assigned action
				}
			}
			break;
		}
	}
}
