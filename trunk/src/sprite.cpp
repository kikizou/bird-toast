#include "sprite.h"


// ----------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------
Sprite::Sprite()
{
	anim = NULL;

	position.x = position.y = 0;
	position.w = position.h = 0;

	velocity.x = 0;
	velocity.y = 0;
}

Sprite::Sprite( Animation *a )
{
	setAnimation( a );
	
	position.x = position.y = 0;
	SDL_Rect area = a->getImage()->getArea();
	position.w = area.w;
	position.h = area.h;

	velocity.x = 0;
	velocity.y = 0;
}


Sprite::~Sprite()
{
	delete anim;
}


// ----------------------------------------------------------------------------
// Accessors
// ----------------------------------------------------------------------------
Animation *Sprite::getAnimation() { return anim; }

SDL_Rect Sprite::getPosition() { return position; }

Vector Sprite::getVelocity() { return velocity; }


// ----------------------------------------------------------------------------
// Mutators
// ----------------------------------------------------------------------------
void Sprite::setAnimation( Animation *a ) { anim = a; }

void Sprite::setPosition( SDL_Rect *p )
{
	position.x = p->x;
	position.y = p->y;
	position.w = p->w;
	position.h = p->h;
}

void Sprite::setVelocity( Vector *v )
{
	velocity = *v;
}


// ----------------------------------------------------------------------------
// Actions
// ----------------------------------------------------------------------------
void Sprite::update()
{
	position.x += (int)velocity.x;
	position.y += (int)velocity.y;
}

void Sprite::draw( SDL_Surface *target )
{
	anim->draw( target, position.x, position.y );
}
