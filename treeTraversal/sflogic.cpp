#include"sflogic.h"
#include<iostream>
void sflogic()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Tree Traversal");
	window.setFramerateLimit(30);
	setModeStart(0);
	menuEvent(&window);
	setModeStart(1);
	gameEvent(&window);
}
void setModeStart(unsigned int m)
{
	if (m == 0)
	{
		Resources::toDrawSprite[0] = 0;
		Resources::toDrawText[1] = 1;
		Resources::toDrawText[0] = 0;
		Resources::toDrawText[2] = 2;
		Resources::toDrawText[3] = 3;
		for (int i = 1; i < 10; i++)
			Resources::toDrawSprite[i] = -1;
		for (int i = 4; i < 20; i++)
			Resources::toDrawText[i] = -1;
	}
	if (m == 1)
	{
		Resources::toDrawSprite[0] = 1;
		for (int i = 1; i < 10; i++)
			Resources::toDrawSprite[i] = -1;
		for (int i = 0; i < 20; i++)
			Resources::toDrawText[i] = -1;
	}
}
void menuEvent(sf::RenderWindow* window)
{
	while (window->isOpen())
	{

		sf::Event event;
		while (window->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (Resources::text[Resources::toDrawText[1]].getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float> (event.mouseButton.y)) | event.mouseButton.button == 0)
					return;
			}
			if (event.type == sf::Event::MouseMoved)
			{
				for (int i = 1; Resources::toDrawText[i] != -1; i++)
				{
					if (Resources::text[Resources::toDrawText[i]].getGlobalBounds().contains(static_cast<float>( event.mouseMove.x),static_cast<float> (event.mouseMove.y)))
					{
						Resources::focusedT(Resources::toDrawText[i]);
					}
					else
						Resources::unfocusedT(Resources::toDrawText[i]);
				}

			}
		}
		window->clear();
		for (int j = 0; Resources::toDrawSprite[j] != -1; j++)
			window->draw(Resources::sprite[Resources::toDrawSprite[j]]);
		for (int j = 0; Resources::toDrawText[j] != -1; j++)
			window->draw(Resources::text[Resources::toDrawText[j]]);
		window->display();
	}
}
void gameEvent(sf::RenderWindow* window)
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				std::cout << event.mouseButton.button << " " << event.mouseButton.x << " " << event.mouseButton.x << std::endl;
			}
		}
		window->clear();
		for (int j = 0; Resources::toDrawSprite[j] != -1; j++)
			window->draw(Resources::sprite[Resources::toDrawSprite[j]]);
		for (int j = 0; Resources::toDrawText[j] != -1; j++)
			window->draw(Resources::text[Resources::toDrawText[j]]);
		window->display();
	}
}