#include "tree.h"
tree::tree()
{
}
tree::tree(std::string d) :data(d), left(NULL), right(NULL)
{
}
tree::tree(std::string d,tree * l,tree* r):data(d),left(l),right(r)
{

}

tree::tree(tree* l, tree* r):left(l),right(r)
{
}

void tree::setParent(tree* p)
{
	parent = p;
}

tree::~tree()
{

}
