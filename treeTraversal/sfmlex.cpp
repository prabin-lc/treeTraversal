#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "resources.h"
int sfmain()
{
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
		window.clear();
	}
	return 0;
}