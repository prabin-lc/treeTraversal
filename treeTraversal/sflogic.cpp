#include"sflogic.h"
#include<iostream>
unsigned isFocused=0;
void sflogic()
{
	bool loop;
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Tree Traversal");
	window.setFramerateLimit(30);
	while (window.isOpen())
	{
		setModeStart(0);
		menuEvent(&window);
		loop = true;
		while (window.isOpen()&&loop)
		{
			Resources::a.reset();
			setModeStart(1);
			loop = gameEvent(&window);
		}
	}
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
		Resources::toDrawText[0] = 4;
		Resources::toDrawText[1] = 5;
		Resources::toDrawText[2] = 6;
		Resources::toDrawText[3] = 8;
		for (int i = 4; i < 20; i++)
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
				if (Resources::text[Resources::toDrawText[1]].getGlobalBounds().contains(relPoint(window,sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))) && event.mouseButton.button == 0)
					return;
				if (Resources::text[Resources::toDrawText[3]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))) && event.mouseButton.button == 0)
					window->close();
			}
			if (event.type == sf::Event::MouseMoved)
			{
					for (int i = 1; Resources::toDrawText[i] != -1; i++)
					{
						if (Resources::text[Resources::toDrawText[i]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)))))
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
bool gameEvent(sf::RenderWindow* window)
{
	isFocused = 0;
	bool isOutput = false;
	sf::Text dispT;
	dispT.setFont(Resources::font[2]);
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (!isOutput)
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (Resources::shape[0].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))))
					{
						if (isFocused != 1)
						{
							Resources::focusedS(0);
							Resources::message.setString("Message:When given valid number of input, click buttons below to generate required tree.");
							isFocused = 1;
						}
					}
					else
					{
						if (isFocused == 1 || isFocused == 2 || isFocused == 3 || isFocused == 4 || isFocused == 5)
						{
							Resources::unfocusedS(0);
							isFocused = 0;
						}
					}
					if (Resources::text[Resources::toDrawText[0]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))) && event.mouseButton.button == 0)
					{
						if (Resources::a.validate())
						{
							Resources::outputT = Resources::a.preorder();
							isOutput = true;
						}
						else
						{
							Resources::message.setString("Message:  Invalid  input.  Don't  forget  to  provide  \"NULL\"  nodes  if  any.");
						}
					}
					else if (Resources::text[Resources::toDrawText[1]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))) && event.mouseButton.button == 0)
					{
						if (Resources::a.validate())
						{
							Resources::outputT = Resources::a.inorder();
							isOutput = true;
						}
						else
						{
							Resources::message.setString("Message:  Invalid  input.  Don't  forget  to  provide  \"NULL\"  nodes  if  any.");
						}
					}
					else if (Resources::text[Resources::toDrawText[2]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))) && event.mouseButton.button == 0)
					{
						if (Resources::a.validate())
						{
							Resources::outputT = Resources::a.postorder();
							isOutput = true;
						}
						else
						{
							Resources::message.setString("Message:  Invalid  input.  Don't  forget  to  provide  \"NULL\"  nodes  if  any.");
						}
					}
					else if (Resources::text[Resources::toDrawText[3]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))) && event.mouseButton.button == 0)
					{
						return true;
					}
				}
				if (isFocused == 1)
				{
					if (event.type == sf::Event::TextEntered)
					{
						unsigned int uni = event.text.unicode;
						if (uni > 31 && uni < 127)
						{
							Resources::a.addC(static_cast<char>(uni));
						}
						else if (uni == 8)
						{
							Resources::a.deleteC();
						}
						else if (uni == 13)
						{
							Resources::a.addS();
						}
					}
				}
				if (event.type == sf::Event::MouseMoved)
				{
					for (int i = 0; Resources::toDrawText[i] != -1; i++)
					{
						if (Resources::text[Resources::toDrawText[i]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)))))
						{
							if (isFocused != i + 2)
							{
								Resources::focusedT(Resources::toDrawText[i]);
								isFocused = i + 2;
								Resources::unfocusedS(0);
							}
							break;
						}
						else
						{
							if (isFocused == i + 2)
							{
								Resources::unfocusedT(Resources::toDrawText[i]);
								isFocused = 0;
							}
						}
					}
				}

			}
			else
			{
				if (Resources::text[Resources::toDrawText[3]].getGlobalBounds().contains(relPoint(window, sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>( event.mouseButton.y)))) && event.mouseButton.button == 0)
				{
				return true;
				}
			}
		}
		window->clear();
		if(isOutput)
		{
			for (int j = 0; Resources::toDrawSprite[j] != -1; j++)
				window->draw(Resources::sprite[Resources::toDrawSprite[j]]);
			window->draw(Resources::text[7]);
			window->draw(Resources::text[8]);
			treeDisplay(window, Resources::outputT,0,0,Resources::a.getHeight());
		}
		else
		{
			for (int j = 0; Resources::toDrawSprite[j] != -1; j++)
				window->draw(Resources::sprite[Resources::toDrawSprite[j]]);
			for (int j = 0; Resources::toDrawText[j] != -1; j++)
				window->draw(Resources::text[Resources::toDrawText[j]]);
			window->draw(Resources::shape[Resources::toDrawShape[0]]);
			for (unsigned j = 0; j < Resources::a.getLength(); j++)
			{
				dispT.setString(*Resources::a.getData(j));
				dispT.setPosition(static_cast < float>(130 + (j / 9) * 250), static_cast < float>(130 + (j * 500/9) % 500));
				window->draw(dispT);
			}
			window->draw(Resources::message);
			Resources::count.setString(std::to_string(Resources::a.getLength()));
			Resources::count.setFillColor(sf::Color(150, 0, 0));
			if (Resources::a.validate())Resources::count.setFillColor(sf::Color(0, 150,0));
			window->draw(Resources::count);
		}
		window->display();
	}
	return true;
}
void treeDisplay(sf::RenderWindow* window, tree* t,int x,int y,int h)
{
	if (h == 0)return;
	y++;
	treeDisplay(window, t->right, x + static_cast<int>(pow(2, h - 2)), y, h - 1);
	sf::Text data;
	data.setString(t->data);
	data.setFont(Resources::font[2]);
	data.setPosition(670.f + x * 40, 170.f + 110 * (y-1));
	window->draw(data);
	treeDisplay(window, t->left, x - static_cast<int>(pow(2, h - 2)), y, h - 1);
}
