#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "resources.h"
void sflogic();
void setModeStart(unsigned int);
void menuEvent(sf::RenderWindow*);
bool gameEvent(sf::RenderWindow*);
void treeDisplay(sf::RenderWindow*, tree*,int,int,int);