#include "menubutton.h"
#include "playingstate.h"

MenuButton::MenuButton()
{
};

MenuButton::MenuButton(GameState &gamestate)
{
    *parent=gamestate;
}

MenuButton::~MenuButton()
{
};

bool MenuButton::isFocused()
{
    if(focused) return true;
    else        return false;  
};

void MenuButton::setFocus(bool value)
{
    focused=value;
};

void MenuButton::onClick()
{
    parent->parent->ChangeState(PlayingState::Instance());
}