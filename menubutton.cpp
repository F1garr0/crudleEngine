#include "menubutton.h"
#include "playingstate.h"

void change()
{
    parent->parent->ChangeState(PlayingState::Instance());
};

MenuButton::MenuButton()
{
 onClick = std::bind(change);
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

/*
void MenuButton::onClick()
{
    parent->parent->ChangeState(PlayingState::Instance());
}*/