#include "resources.h"

sf::Font* Resources::font=new sf::Font;
sf::Texture* Resources::texture = new sf::Texture [2];
void Resources::load()
{
	font->loadFromFile("chalkboard.ttf");
	texture[0].loadFromFile("door.png");
	texture[1].loadFromFile("board.png");
}
