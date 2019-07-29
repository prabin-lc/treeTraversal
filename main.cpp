#include<iostream>
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include "treeTraversal/treeTraversal/inputTree.h"
#include "treeTraversal/treeTraversal/tree.h"
#include "treeTraversal/treeTraversal/sfmlex.h"
#include "treeTraversal/treeTraversal/resources.h"
using namespace std;
int main()
{
	sf::Thread thread(&sfmain);
	thread.launch();
	//inputTree a;
	//for (int i = 0; i < 50; i++)cout << "-";
	//a.print2D(a.prefix());
	//for (int i = 0; i < 50; i++)cout << "-";
	//a.print2D(a.infix());
	//for (int i = 0; i < 50; i++)cout << "-";
	//a.print2D(a.postfix());
	return 0;
}