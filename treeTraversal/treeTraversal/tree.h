#pragma once
#include<iostream>
class tree
{
	std::string data;
	tree* left, * right,*parent=NULL;
public:
	tree();
	tree(std::string);
	tree(std::string, tree*, tree*);
	tree(tree*, tree*);
	void setParent(tree*);
	friend class inputTree;
	~tree();
};

