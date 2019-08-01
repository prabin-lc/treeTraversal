#pragma once
#include<SFML/Graphics.hpp>

class Resources 
{
public:
	static sf::Font *font;
	static sf::Texture *texture;
	static sf::Sprite* sprite;
	static sf::Text* text;
	static void load();
	static int toDrawSprite[10];
	static int toDrawText[20];
	static void focusedT(int);
	static void unfocusedT(int);
	static void focusedS(int);
	static void unfocusedS(int);
	~Resources();
};