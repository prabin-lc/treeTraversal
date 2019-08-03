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
	void reset();
	void addS();
	void addC(char);
	void deleteC();
	bool validate();
	tree* preorder();
	tree* preorder(int, int);
	tree* postorder();
	tree* postorder(int, int);
	tree* inorder();
	tree* inorder(int h, unsigned int c);
	unsigned getLength();
	unsigned getHeight();
	std::string* getData(int n);
	void print2DUtil(tree*, int);
	void print2D(tree*);
	friend class Resources;
};

