#ifndef MAINMENUSTATE
#define MAINMENUSTATE

#include "gamestate.h"
#include "menubutton.h"

class MainMenuState : public GameState
{
public:
	void Init();
	
    void Cleanup();
	
    void Pause();
	void Resume();
	
    void HandleEvents(sf::RenderWindow &window);
    
    void Update(sf::RenderWindow &window);
    void Draw(sf::RenderWindow &window);

	static MainMenuState* Instance();

protected:
	MainMenuState();

private:
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::Sprite *button;
    sf::Texture *buttonTexture;
    sf::Text *buttonText;
    sf::Font *font;
    MenuButton *buttonBegin;
    bool inButtonBoundary;
};

#endif