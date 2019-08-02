#include "resources.h"
inputTree Resources::a;
sf::Font* Resources::font=new sf::Font[2];
sf::Texture* Resources::texture = new sf::Texture [2];
sf::Sprite* Resources::sprite = new sf::Sprite[2];
sf::Text* Resources::text = new sf::Text[10];
sf::RectangleShape* Resources::shape = new sf::RectangleShape[1];
int Resources::toDrawSprite[10];
int Resources::toDrawText[20];
int Resources::toDrawShape[1];
void Resources::load()
{
	font[0].loadFromFile("res/Keshya.ttf");
	font[1].loadFromFile("res/montserrat.ttf");
	texture[0].loadFromFile("res/menu.png");
	texture[1].loadFromFile("res/board.png");
	sprite[0].setTexture(texture[0]);
	sprite[1].setTexture(texture[1]);
	text[0].setString("Tree Constructor");
	text[0].setStyle(sf::Text::Bold|sf::Text::Underlined);
	text[0].setFillColor(sf::Color(86, 90, 255));
	text[0].setOutlineThickness(1.f);
	text[0].setCharacterSize(50);
	text[0].setFont(font[0]);
	text[0].setPosition(100.f, 150.f);
	text[1].setString("1.  Start");
	text[1].setCharacterSize(30);
	text[1].setFont(font[1]);
	text[1].setFillColor(sf::Color::Black);
	text[1].setPosition(100.f, 290.f);
	text[2].setString("2.  About");
	text[2].setCharacterSize(30);
	text[2].setFont(font[1]);
	text[2].setFillColor(sf::Color::Black);
	text[2].setPosition(100.f, 340.f);
	text[3].setString("3.  Exit");
	text[3].setCharacterSize(30);
	text[3].setFont(font[1]);
	text[3].setFillColor(sf::Color::Black);
	text[3].setPosition(100.f, 390.f);
	shape[0].setSize(sf::Vector2f(500.f,600.f));
	shape[0].setPosition(100.f, 90.f);
	shape[0].setFillColor(sf::Color::Transparent);

}
void Resources::focusedT(int n)
{
	Resources::text[n].setCharacterSize(32);
	Resources::text[n].setOutlineColor(sf::Color(86, 150, 227));
}
void Resources::unfocusedT(int n)
{
	Resources::text[n].setCharacterSize(30);
	Resources::text[n].setOutlineColor(sf::Color::White);
}
void Resources::focusedS(int n)
{
	shape[n].setOutlineThickness(1.f);
	shape[n].setFillColor(sf::Color(90, 90, 110, 32));
}
void Resources::unfocusedS(int n)
{
	shape[n].setOutlineThickness(0);
	shape[n].setFillColor(sf::Color::Transparent);
}
Resources::~Resources()
{
	delete[] font;
	delete[] texture;
	delete[] sprite;
	delete[] text;
}

