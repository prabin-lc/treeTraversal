#pragma once
#include<SFML/Graphics.hpp>
#include "inputTree.h"

class Resources 
{
public:
	static inputTree a;

	static sf::Font *font;
	static sf::Texture *texture;

	static sf::Sprite* sprite;
	static int toDrawSprite[10];

	static sf::Text* text;
	static int toDrawText[20];

	static sf::RectangleShape* shape;
	static int toDrawShape[1];

	static void focusedT(int);
	static void unfocusedT(int);

	static void focusedS(int);
	static void unfocusedS(int);

	static void load();

	~Resources();
};