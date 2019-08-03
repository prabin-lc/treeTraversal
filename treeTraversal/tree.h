#pragma once
#include<iostream>
class tree
{
public:
	std::string data;
	tree* left, * right;
	tree();
	tree(std::string);
	tree(std::string, tree*, tree*);
	tree(tree*, tree*);
	~tree();
};

