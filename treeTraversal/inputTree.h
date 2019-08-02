#pragma once
#include<iostream>
#include<cmath>
#include "tree.h"
class inputTree
{
	std::string data[50];
	unsigned int length=0,height=0;
public:
	inputTree();
	inputTree(int);
	void addS();
	void addC(char);
	void deleteC();
	bool validate();
	tree* prefix();
	tree* prefix(int, int);
	tree* postfix();
	tree* postfix(int, int);
	tree* infix();
	tree* infix(int h, unsigned int c);
	void print2DUtil(tree*, int);
	void print2D(tree*);
};

