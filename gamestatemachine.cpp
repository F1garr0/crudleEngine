#include "gamestatemachine.h"
#include "gamestate.h"
#include <SFML/Graphics.hpp>

    GameStateMachine::GameStateMachine(){};
    GameStateMachine::~GameStateMachine(){};
    void GameStateMachine::Init(){};
    void GameStateMachine::Cleanup(){};
    
    void GameStateMachine::ChangeState(GameState *state)
    {
        if ( !states.empty() ) 
        {
		    states.back()->Cleanup();
		    states.pop_back();
	    }
	    states.push_back(state);
	    states.back()->Init();
        states.back()->parent=this;
    };

    void GameStateMachine::PushState(GameState *state){states.push_back(state);};
    void GameStateMachine::PopState(GameState *state){states.pop_back();};
    
    void GameStateMachine::EventHandle(sf::RenderWindow &window){states.back()->HandleEvents(window);};
    void GameStateMachine::Update(sf::RenderWindow &window){states.back()->Update(window);};
    void GameStateMachine::Draw(sf::RenderWindow &window){states.back()->Draw(window);};
    
    bool GameStateMachine::Running(){return true;};
    void GameStateMachine::Quit(){};