#pragma once
#include<iostream>
#include<cmath>
#include "tree.h"
class inputTree
{
	int count=0;
	std::string data[50];
	int length,height;
public:
	inputTree();
	tree* prefix();
	tree* prefix(int h, int c);
	tree* postfix();
	tree* postfix(int h, int c);
	tree* infix();
	tree* infix(int h, int c);

};

