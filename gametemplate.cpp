#include <SFML/Graphics.hpp>

#define WINDOWTITLE "Game App"


class EventHandler
{
public:
    EventHandler(){};
    ~EventHandler(){};
    void operator()(sf::RenderWindow &window){handle(window);};
    static void handle(sf::RenderWindow &window)
    {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
    };

};


class GameApp
{
public:
    GameApp()
    {
        sf::Vector2f resolution;
        resolution.x = sf::VideoMode::getDesktopMode().width;
        resolution.y = sf::VideoMode::getDesktopMode().height;
        Window.create(sf::VideoMode(resolution.x, resolution.y), WINDOWTITLE);
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

    void update(){};

    void draw()
    {
        Window.clear();
        Window.display();
    };

    void handleEvents()
    {
        EventHandler::handle(Window);
    };     

    sf::RenderWindow Window;

};



int main()
{
    GameApp game;
    return game.exec();
}