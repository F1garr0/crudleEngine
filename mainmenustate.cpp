#include "mainmenustate.h"
#include "playingstate.h"

void MainMenuState::Init()
{
    texture       = new sf::Texture;
    buttonTexture = new sf::Texture;
    sprite        = new sf::Sprite ;
    button        = new sf::Sprite ;
    font          = new sf::Font   ;
    buttonText    = new sf::Text   ;

    buttonBegin = new MenuButton;
    buttonBegin->parent=this;


    texture->loadFromFile("Resources/testimg.jpg")  ;
    buttonTexture->loadFromFile("Resources/btn.png");
    
    sprite->setTexture(*texture)                            ;
    button->setTexture(*buttonTexture)                      ;
    button->setTextureRect(sf::IntRect(0,680,2000,1130-680));
    button->scale(0.25,0.25)                                ;
    button->setPosition(800,400)                            ;
    
    font->loadFromFile("Resources/Relapse.ttf");
    buttonText->setFont(*font)                 ;
    buttonText->setString("Begin game")        ;
    buttonText->setColor(sf::Color::Black)     ;
    buttonText->scale(1.25,1.25)               ;
    buttonText->setPosition(button->getPosition().x+110,button->getPosition().y+30);

    inButtonBoundary=false;
};


void MainMenuState::Cleanup()
{
    delete texture      ;
    delete buttonTexture;
    delete sprite       ;
    delete button       ;
    delete font         ;
    delete buttonText   ;
};

void MainMenuState::Pause(){};
void MainMenuState::Resume(){};

void MainMenuState::HandleEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
            break;
                
            case sf::Event::MouseMoved:
                if(
                    sf::Mouse::getPosition(window).x>button->getPosition().x && 
                    sf::Mouse::getPosition(window).y>button->getPosition().y &&
                    sf::Mouse::getPosition(window).x<button->getPosition().x+2000*0.25 &&
                    sf::Mouse::getPosition(window).y<button->getPosition().y+450*0.25
                ){
                    button->setTextureRect(sf::IntRect(0,0,2000,450));
                    inButtonBoundary=true;
                }
                else{
                    button->setTextureRect(sf::IntRect(0,680,2000,1130-680));
                    inButtonBoundary=false;
                }
            break;

            case sf::Event::MouseButtonReleased:
                if(inButtonBoundary && event.key.code == sf::Mouse::Left)
                {
                    //stateMachine->ChangeState(PlayingState::Instance());
                    buttonBegin->onClick();
                }
            break;
        
        }
        
    }
};

void MainMenuState::Update(sf::RenderWindow &window)
{
    
};

void MainMenuState::Draw(sf::RenderWindow &window)
{
    window.clear(sf::Color(0xf7f0d400));
    window.draw(*sprite);
    window.draw(*button);
    window.draw(*buttonText);
};

MainMenuState* MainMenuState::Instance()
{
    static MainMenuState mainMenuState;
    return &mainMenuState;
};

MainMenuState::MainMenuState()
{};