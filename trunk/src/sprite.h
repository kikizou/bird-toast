#ifndef BT_SPRITE_H
#define BT_SPRITE_H
#include "gamescreen.h"
#include "physics.h"

//============================================================================
// Class       : Sprite
// Author      : Nate Slottow
// Description : Basic non-static physical and visual entity
//============================================================================
class Sprite : public Drawable
{
public:
	Sprite();
	Sprite( Animation *a );
	~Sprite();

	// Accessors
	Animation *getAnimation();
	SDL_Rect getPosition();
	Vector getVelocity();

	// Mutators
	void setAnimation( Animation *a );
	void setPosition( SDL_Rect *p );
	void setVelocity( Vector *v );

	// Actions
	void update();
	void draw( SDL_Surface *target );

private:
	Animation *anim;

	SDL_Rect position;

	Vector velocity;
};

#endif
