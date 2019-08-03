#include "inputTree.h"

inputTree::inputTree()
{
}

inputTree::inputTree(int)
{
	while (1) {
		std::string d[50];
		length = 0;
		height = 0;
		int t = 2;
		std::string temp;
		bool stat=false;
		std::cout << "Enter the data of tree in a order:\nEnter done after done." << std::endl;
		for (int i = 0; i < 50; i++)
		{
			std::cin;
			std::cin >> temp;
			if (temp == "DONE" || temp == "done")break;
			stat = false;
			d[i] = temp;
			length++;
			if ((i+2)/t==1) {
				height++;
				t *= 2;
				stat = true;
			}
		}
		if (stat) {
			for (unsigned int i = 0; i < length; i++)
				data[i] = d[i];
			break;
		}
		std::cout << "\ninvalid input.\nDid you forget to specify NULL nodes?\n" << std::endl;
	}
}
void inputTree::reset()
{
	for (int i = 0; i < length; i++)
	{
		data[i] = "";
	}
	length = 0; height = 0;
}
void inputTree::addS()
{
	if (data[length-1] == "")return;
	else
	{
		length++;
		height = static_cast<unsigned>(log2(length + 1));
	}
}

void inputTree::addC(char c)
{
	if (length == 0 && data[length] == "")
	{
		length++;
		height++;
	}
	data[length - 1] += c;
}

void inputTree::deleteC()
{
	if (length == 0 && data[length] == "")return;
	if (data[length-1]=="")
		height = static_cast<unsigned>(log2(--length + 1));
	else
		data[length-1].erase(data[length-1].length()-1);
}

bool inputTree::validate()
{
	if (length == 0)return false;
	if (fabs(length-pow(2,height)+1)<0.0001) return true;
	return false;
}
tree* inputTree::prefix()
{
	return prefix(height,0);
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
	return postfix(height,static_cast<int>(pow(2, height))- 2);
}

tree* inputTree::postfix(int h, int c)
{
	tree* newtree = new tree;
	newtree->data = data[c];
	if (h == 1)
	{
		newtree->left = nullptr;
		newtree->right = nullptr;
		return newtree;
	}
	newtree->left = postfix(h-1,c-static_cast<int>(pow(2,h-1)));
	newtree->right = postfix(h-1,c-1);
	return newtree;
}

tree* inputTree::infix()
{
	return infix(height,static_cast<unsigned int>(pow(2,height-1)-1));
}

tree* inputTree::infix(int h,unsigned int c)
{
	tree* newtree = new tree;
	newtree->data = data[c];
	if (h == 1) {
		newtree->left = nullptr;
		newtree->right = nullptr;
		return newtree;
	}
	newtree->left = infix(h - 1, c - static_cast<int>(pow(2, h - 2)));
	newtree->right = infix(h - 1, c + static_cast<int>(pow(2, h - 2)));
	return newtree;
}

unsigned inputTree::getLength()
{
	return length;
}
unsigned inputTree::getHeight()
{
	return height;
}
std::string* inputTree::getData(int n)
{
	return &data[n];
}

void inputTree::print2DUtil(tree* root, int space)
{
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += 10;

	// Process right child first  
	print2DUtil(root->right, space);

	// Print current node after space  
	// count  
	std::cout << std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";

	// Process left child  
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()  
void inputTree::print2D(tree* root)
{
	// Pass initial space count as 0  
	print2DUtil(root, 0);
}

