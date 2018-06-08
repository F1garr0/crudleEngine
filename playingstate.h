#ifndef PLAYINGSTATE
#define PLAYINGSTATE

#include "gamestate.h"

class PlayingState : public GameState
{
public:
    void Init();
    void Cleanup();

    void Pause();
    void Resume();

    void HandleEvents(sf::RenderWindow &window, GameStateMachine* stateMachine);
    void Update(sf::RenderWindow &window);
    void Draw(sf::RenderWindow &window);

    static PlayingState* Instance();
    
protected:
    PlayingState();

private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif