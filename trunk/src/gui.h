#ifndef BT_GUI_ELEMENTS_H
#define BT_GUI_ELEMENTS_H
#include <vector>
#include "input.h"
#include "image.h"

using namespace std;

//============================================================================
// Class       : GUIElement
// Author      : Nate Slottow
// Description : Basic visual element of GUI
//============================================================================
class GUIElement
{
public:
	// Constructors
	GUIElement();
	GUIElement( GUIElement *parent );
	GUIElement( EventHandlerCallback eventHandler );
	GUIElement( GUIElement *parent, EventHandlerCallback eventHandler );
	~GUIElement();

	// Accessors
	bool isActive();
	bool isVisible();
	bool isFocused();

	GUIElement *getParent();

	SDL_Rect getPosition();

	Animation *getAnimation();


	// Mutators
	void setActive( bool active );
	void setVisible( bool visible );
	void setFocused( bool focused );

	void setParent( GUIElement *parent );
	void setTarget( GUIElement *target );

	void setEventHandler( EventHandlerCallback eventHandler );

	void setPosition( SDL_Rect *position );

	void setAnimation( Animation *anim );

	void addChild( GUIElement *element );

	// Actions
	virtual void handleEvent( SDL_Event *event );

	virtual void draw( SDL_Surface *target );

protected:
	bool active;
	bool visible;
	bool focused;

	GUIElement *parent;
	GUIElement *target;		// Set if this element modifies another
	vector<GUIElement *> children;

	EventHandlerCallback eventHandler;

	SDL_Rect position;		// position relative to parent

	Animation *anim;
};


//============================================================================
// Class       : GUIPanel
// Author      : Nate Slottow
// Description : Floating GUIElement container
//============================================================================
class GUIPanel : public GUIElement
{
};


//============================================================================
// Class       : GUIButton
// Author      : Nate Slottow
// Description : A click button.  Enough said.
//============================================================================
// TODO: implement captions
//============================================================================
class GUIButton : public GUIElement
{
public:
	GUIButton();
	~GUIButton();

	// Actions
	void handleEvent( SDL_Event *event );

private:
	bool hover;
	bool press;
	bool click;

	// 4 row animation (image)
	/*
	 * 1: inactive (default)
	 * 2: hover
	 * 3: active
	 * 4: pressed
	 */
};


#endif
