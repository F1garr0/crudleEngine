#ifndef GAMESTATEMACHINE
#define GAMESTATEMACHINE

#include <SFML/Graphics.hpp>

class GameState;

class GameStateMachine
{
public:
    GameStateMachine();
    ~GameStateMachine();
    void Init();
    void Cleanup();
    
    void ChangeState(GameState *state);

    void PushState(GameState *state);
    void PopState(GameState *state);
    
    void EventHandle(sf::RenderWindow &window);
    void Update(sf::RenderWindow &window);
    void Draw(sf::RenderWindow &window);
    

    bool Running();
    void Quit();

    std::vector<GameState*> states;
    bool m_running;
};

#endif