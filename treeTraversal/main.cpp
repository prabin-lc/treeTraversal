#include<iostream>
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include "inputTree.h"
#include "tree.h"
#include "sfmlex.h"
#include "resources.h"
using namespace std;
int main()
{
	Resources::load();
	sfmain();

	//inputTree a;
	//for (int i = 0; i < 50; i++)cout << "-";
	//a.print2D(a.prefix());
	//for (int i = 0; i < 50; i++)cout << "-";
	//a.print2D(a.infix());
	//for (int i = 0; i < 50; i++)cout << "-";
	//a.print2D(a.postfix());
	return 0;
}