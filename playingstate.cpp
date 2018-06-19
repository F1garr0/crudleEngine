#include "playingstate.h"
#include "mainmenustate.h"

void PlayingState::Init()
{
    texture.loadFromFile("Resources/hero.png");
    sprite.setTexture(texture);
};

void PlayingState::Cleanup()
{

};

void PlayingState::Pause(){};
void PlayingState::Resume(){};

void PlayingState::HandleEvents(sf::RenderWindow &window)
{
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                parent->ChangeState(MainMenuState::Instance());
            }
        }
};

void PlayingState::Update(sf::RenderWindow &window)
{

};

void PlayingState::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
};

PlayingState* PlayingState::Instance()
{
    static PlayingState playingState;
    return &playingState;
};

PlayingState::PlayingState(){};