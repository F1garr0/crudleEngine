#ifndef MENUBUTTON
#define MENUBUTTON

#include <SFML/Graphics.hpp>
#include "gamestate.h"
//#include <functional>


class MenuButton : public sf::Sprite
{
private:
    sf::Texture texture;
    bool focused;


public:
    MenuButton(/* args */);
    ~MenuButton();
    bool isFocused();
    //std::function onClick;
    GameState *parent;
    

};


#endif