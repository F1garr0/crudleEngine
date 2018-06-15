#ifndef MENUBUTTON
#define MENUBUTTON

#include <SFML/Graphics.hpp>
#include "gamestate.h"
//#include <functional>


class MenuButton : public sf::Sprite
{
private:
    sf::Texture defaultTexture;
    sf::Texture focusedTexture;
    bool focused;
    sf::IntRect bounds;

public:
    MenuButton();
    MenuButton(GameState &gamestate);
    ~MenuButton();
    bool isFocused();
    void loadTexture(sf::String stringPath);
    void setFocus(bool value);
    bool isMouseInBounds(sf::Window &window);
    //std::function onClick;
    GameState *parent;
    void onClick();

};


#endif