#include<iostream>
#include "treeTraversal/treeTraversal/inputTree.h"
#include "treeTraversal/treeTraversal/tree.h"
using namespace std;
int main()
{
	inputTree a;
	for (int i = 0; i < 50; i++)cout << "-";
	a.print2D(a.prefix());
	for (int i = 0; i < 50; i++)cout << "-";
	a.print2D(a.infix());
	for (int i = 0; i < 50; i++)cout << "-";
	a.print2D(a.postfix());
	return 0;
}