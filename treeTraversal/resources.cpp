#include "resources.h"
inputTree Resources::a;
tree* Resources::outputT;
sf::Text Resources::message;
sf::Text Resources::count;
sf::Font* Resources::font=new sf::Font[3];
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
	font[2].loadFromFile("res/chalkboard.ttf");
	texture[0].loadFromFile("res/menu.png");
	texture[1].loadFromFile("res/board.png");
	sprite[0].setTexture(texture[0]);
	sprite[1].setTexture(texture[1]);
	text[0].setString("Tree Generator");
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
	shape[0].setSize(sf::Vector2f(1160.f,500.f));
	shape[0].setPosition(110.f, 125.f);
	shape[0].setFillColor(sf::Color::Transparent);
	text[4].setString("1. PREORDER");
	text[4].setCharacterSize(30);
	text[4].setFont(font[2]);
	text[4].setPosition(100.f, 650.f);
	text[4].setStyle(sf::Text::Bold | sf::Text::Underlined);
	text[5].setString("2. INORDER");
	text[5].setCharacterSize(30);
	text[5].setFont(font[2]);
	text[5].setPosition(500.f, 650.f);
	text[5].setStyle(sf::Text::Bold | sf::Text::Underlined);
	text[6].setString("3. POSTORDER");
	text[6].setCharacterSize(30);
	text[6].setFont(font[2]);
	text[6].setPosition(900.f, 650.f);
	text[6].setStyle(sf::Text::Bold | sf::Text::Underlined);
	text[7].setString("TREE:");
	text[7].setCharacterSize(40);
	text[7].setFont(font[2]);
	text[7].setPosition(610.f, 110.f);
	text[7].setStyle(sf::Text::Bold | sf::Text::Underlined);
	text[8].setString("Reset");
	text[8].setCharacterSize(30);
	text[8].setFont(font[2]);
	text[8].setPosition(1200.f, 90.f);
	text[8].setStyle(sf::Text::Bold | sf::Text::Underlined);
	message.setString("Message:  Click  on  the  board  to  give  input  data.");
	message.setCharacterSize(20);
	message.setFont(font[2]);
	message.setPosition(110.f, 100.f);
	message.setStyle(sf::Text::Bold|sf::Text::Underlined);
	count.setFont(font[2]);
	count.setCharacterSize(40);
	count.setPosition(1240.f,650.f);
	count.setOutlineThickness(1);
	count.setOutlineColor(sf::Color::White);
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

