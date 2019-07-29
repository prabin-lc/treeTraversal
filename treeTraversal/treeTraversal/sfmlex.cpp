#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "resources.h"
int sfmain()
{
	sf::Texture door;
	door.loadFromFile("door.png");
	sf::Sprite doorSprite(door);
	doorSprite.scale(sf::Vector2f(0.5f, 0.5f));
	doorSprite.setPosition(sf::Vector2f(550.f, 40.f));
	doorSprite.setColor(sf::Color(255, 255, 255,128));
	sf::Font f;
	f.loadFromFile("chalkboard.ttf");
	sf::RenderWindow window(sf::VideoMode(1366, 768), "My title", sf::Style::Default);
	window.setFramerateLimit(30);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color(0,128,55));
		window.draw(doorSprite);

		window.display();
	}
	return 0;
}