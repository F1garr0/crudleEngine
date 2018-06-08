#include "gamestate.h"
#include "gamestatemachine.h"

void GameState::Init(){};
void GameState::Cleanup(){};
void GameState::HandleEvents(sf::RenderWindow &window, GameStateMachine *stateMachine){};
void GameState::Update(sf::RenderWindow &window){};
void GameState::Draw(sf::RenderWindow &window){};