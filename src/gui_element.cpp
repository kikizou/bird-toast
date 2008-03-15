#include "gui.h"


// ----------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------
GUIElement::GUIElement()
{
	active = false;
	visible = false;
	focused = false;

	parent = NULL;

	eventHandler = NULL;

	position.x = position.y = 0;
	position.w = position.h = 0;

	anim = NULL;
}

GUIElement::GUIElement( GUIElement *parent )
{
	active = false;
	visible = false;
	focused = false;

	this->parent = parent;

	eventHandler = NULL;

	position.x = position.y = 0;
	position.w = position.h = 0;

	anim = NULL;
}

GUIElement::GUIElement( EventHandlerCallback eventHandler )
{
	active = false;
	visible = false;
	focused = false;

	parent = NULL;

	this->eventHandler = eventHandler;

	position.x = position.y = 0;
	position.w = position.h = 0;

	anim = NULL;
}

GUIElement::GUIElement( GUIElement *parent, EventHandlerCallback eventHandler )
{
	active = false;
	visible = false;
	focused = false;

	this->parent = parent;

	this->eventHandler = eventHandler;

	position.x = position.y = 0;
	position.w = position.h = 0;

	anim = NULL;
}

GUIElement::~GUIElement()
{
	// Delete children
	for( unsigned int i = 0; i < children.size(); i++ )
	{
		if( children[i] != NULL )
		{
			delete children[i];
		}
	}
	children.clear();

	// Delete animation
	delete anim;
}


// ----------------------------------------------------------------------------
// Accessors
// ----------------------------------------------------------------------------
bool GUIElement::isActive() { return active; }

bool GUIElement::isVisible() { return visible; }

bool GUIElement::isFocused() { return focused; }

GUIElement *GUIElement::getParent() { return parent; }

SDL_Rect GUIElement::getPosition() { return position; }

Animation *GUIElement::getAnimation() { return anim; }


// ----------------------------------------------------------------------------
// Mutators
// ----------------------------------------------------------------------------
void GUIElement::setActive( bool active ) { this->active = active; }

void GUIElement::setVisible( bool visible )
{
	this->visible = visible;
	if( visible )
	{
		anim->reset();
		anim->start();
	}
	else
	{
		anim->stop();
		anim->reset();
	}
}

void GUIElement::setFocused( bool focused ) { this->focused = focused; }

void GUIElement::setParent( GUIElement *parent ) { this->parent = parent; }

void GUIElement::setTarget( GUIElement *target ) { this->target = target; }

void GUIElement::setEventHandler( EventHandlerCallback eventHandler )
{
	this->eventHandler = eventHandler;
}

void GUIElement::setPosition( SDL_Rect *position )
{
	this->position.x = position->x;
	this->position.y = position->y;
	this->position.w = position->w;
	this->position.h = position->h;
}

void GUIElement::setAnimation( Animation *anim ) { this->anim = anim; }

void GUIElement::addChild( GUIElement *element )
{
	element->setParent( this );
	children.push_back( element );
}


// ----------------------------------------------------------------------------
// Actions
// ----------------------------------------------------------------------------
void GUIElement::handleEvent( SDL_Event *event )
{
	if( active )
	{
		eventHandler( event, this );

		// update children
		for( unsigned int i = 0; i < children.size(); i++ )
		{
			children[i]->handleEvent( event );
		}
	}
}

void GUIElement::draw( SDL_Surface *target)
{
	/* template for virtual function */
	if( visible )
	{
		// Draw relative to parent
		if( parent != NULL )
		{
			SDL_Rect parentPos = parent->getPosition();
			anim->draw( target,
						position.x + parentPos.x,
						position.y + parentPos.y );

			// Draw children
			for( unsigned int i = 0; i < children.size(); i++ )
				children[i]->draw( target );
		}
		else
		{
			anim->draw( target, position.x, position.y );
		}
	}
}
