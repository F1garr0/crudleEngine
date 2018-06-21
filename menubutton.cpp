#include "menubutton.h"
#include "playingstate.h"
#include <iostream>

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
