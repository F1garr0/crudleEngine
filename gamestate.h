#ifndef GAMESTATE
#define GAMESTATE

#include "gamestatemachine.h"
#include "SFML/Graphics.hpp"

class GameState
{
public:
    virtual void Init();
    virtual void Cleanup();
    virtual void HandleEvents(sf::RenderWindow &window, GameStateMachine *stateMachine);
    virtual void Update(sf::RenderWindow &window);
    virtual void Draw(sf::RenderWindow &window);
};

#endif
