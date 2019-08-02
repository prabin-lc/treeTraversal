#include"sflogic.h"
#include<iostream>
unsigned isFocused=0;
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
		Resources::toDrawShape[0] = 0;
	}
}
sf::Vector2f relPoint(sf::RenderWindow* window, sf::Vector2f a)
{
	a.x = a.x * 1366 / window->getSize().x;
	a.y = a.y * 768 / window->getSize().y;
	return a;
}
void menuEvent(sf::RenderWindow* window)
{
	isFocused = 0;
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
				if (Resources::text[Resources::toDrawText[1]].getGlobalBounds().contains(relPoint(window,sf::Vector2f(event.mouseButton.x,event.mouseButton.y))) && event.mouseButton.button == 0)
					return;
				if (Resources::text[Resources::toDrawText[3]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) && event.mouseButton.button == 0)
					window->close();
			}
			if (event.type == sf::Event::MouseMoved)
			{
					for (int i = 1; Resources::toDrawText[i] != -1; i++)
					{
						if (Resources::text[Resources::toDrawText[i]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(event.mouseMove.x, event.mouseMove.y))))
						{
							if (isFocused != i)
							{
								Resources::focusedT(Resources::toDrawText[i]);
								isFocused = i;
							}
						}
						else
						{
							if (isFocused == i)
							{
								Resources::unfocusedT(Resources::toDrawText[i]);
								isFocused = 0;
							}
						}
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
	isFocused = 0;
	std::string tempInput="";
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
				if (Resources::shape[0].getGlobalBounds().contains(relPoint(window, sf::Vector2f(event.mouseButton.x, event.mouseButton.y))))
				{ 
					if (isFocused != 1)
					{
						Resources::focusedS(0);
						isFocused = 1;
					}
				}
				else
					if (isFocused == 1)
					{
						Resources::unfocusedS(0);
						isFocused = 0;
					}
			}
			if (event.type == sf::Event::TextEntered)
			{
				unsigned int uni = event.text.unicode;
				if (uni> 31 && uni < 127)
				{
					tempInput += static_cast<char>(uni);
				}
				if (uni == 13);

				std::cout << uni << std::endl;
			}
		}
		window->clear();
		for (int j = 0; Resources::toDrawSprite[j] != -1; j++)
			window->draw(Resources::sprite[Resources::toDrawSprite[j]]);
		for (int j = 0; Resources::toDrawText[j] != -1; j++)
			window->draw(Resources::text[Resources::toDrawText[j]]);
		window->draw(Resources::shape[Resources::toDrawShape[0]]);
		window->display();
	}
}