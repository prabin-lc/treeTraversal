#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "resources.h"
int sfmain()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Tree Traversal Explorer", sf::Style::Default);
	window.setFramerateLimit(30);
	sf::Sprite doorSprite(Resources::texture[0]);
	doorSprite.setScale(0.5f, 0.5f);
	doorSprite.setPosition(sf::Vector2f(650.f, 10.f));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color(128,128,255));
		window.draw(doorSprite);
		window.display();
	}
	return 0;
}