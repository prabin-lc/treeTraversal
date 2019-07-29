#pragma once
#include<iostream>
class tree
{
	std::string data;
	tree* left, * right;
public:
	tree();
	tree(std::string);
	tree(std::string, tree*, tree*);
	tree(tree*, tree*);
	friend class inputTree;
	~tree();
};

