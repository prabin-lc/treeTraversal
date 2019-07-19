#include "inputTree.h"

inputTree::inputTree():length(0),height(0),count(0)
{

	while (1) {
		length = 0;
		height = 0;
		int t = 2;
		std::string temp;
		bool stat=false;
		std::cout << "Enter the data of tree in a order:\nEnter done after done." << std::endl;
		for (int i = 0; i < 50; i++)
		{
			std::cin >> temp;
			if (temp == "DONE" || temp == "done")break;
			stat = false;
			data[i] = temp;
			length++;
			if ((i+2)/t==1) {
				height++;
				t *= 2;
				stat = true;
			}
		}
		if (stat) break;
		std::cout << "\ninvalid input.\nDid you forget to specify NULL nodes?\n" << std::endl;
	}
}
tree* inputTree::prefix()
{
	return prefix(height, count);
}
tree* inputTree::prefix(int h,int c)
{
	tree* newtree = new tree;
	newtree->data = data[c];
	if (h == 1) {
		newtree->left = nullptr;
		newtree->right = nullptr;
		return newtree;
	}
	newtree->left = prefix(h - 1, c + 1);
	newtree->right = prefix(h - 1, c + static_cast<int>(pow(2, h - 1)));
	return newtree;
}

tree* inputTree::postfix()
{
	return postfix(height,count);
}

tree* inputTree::postfix(int h, int c)
{
	return nullptr;
}

tree* inputTree::infix()
{
	return infix(height,count=static_cast<int>(pow(2,height)/2));
}

tree* inputTree::infix(int h, int c)
{
	tree* newtree = new tree;
	newtree->data = data[c];
	if (h == 1) {
		newtree->left = nullptr;
		newtree->right = nullptr;
		return newtree;
	}
	newtree->left = infix(h - 1, c - static_cast<int>(pow(2, h - 1)));
	newtree->right = infix(h - 1, static_cast<int>(c + pow(2, h - 1)));
	return newtree;
}
