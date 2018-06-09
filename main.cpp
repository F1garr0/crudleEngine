#include <SFML/Graphics.hpp>
#include <boost/filesystem.hpp>
#include <vector>
#include <iostream>
#include "gamestatemachine.h"
#include "gamestate.h"
#include "mainmenustate.h"

#define WINDOWTITLE "Game App"

class GameApp
{
public:
    GameApp()
    {
        sf::Vector2f resolution;
        resolution.x = sf::VideoMode::getDesktopMode().width;
        resolution.y = sf::VideoMode::getDesktopMode().height;
        Window.create(sf::VideoMode(resolution.x, resolution.y), WINDOWTITLE,sf::Style::Close);
        stateMachine.ChangeState(MainMenuState::Instance());
    };

    ~GameApp(){};

    int exec()
    {
        while(Window.isOpen())
        {                
            handleEvents();
            update();
            draw();
        }
        return 0;
    };

    void update()
    {
        stateMachine.Update(Window);
    };

    void draw()
    {
        Window.clear();
        stateMachine.Draw(Window);
        Window.display();  
    };

    void handleEvents()
    {
        stateMachine.EventHandle(Window);
    };     

    sf::RenderWindow Window;
    GameStateMachine stateMachine;

};


int main()
{
    GameApp game;
    return game.exec();
}
