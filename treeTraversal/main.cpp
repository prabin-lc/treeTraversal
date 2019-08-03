#include<iostream>
#include "resources.h"
#include "sflogic.h"

int main()
{
	bool cui=false;
	//std::cout << "CUI??? :";
	//std::cin >> cui;
	if (cui)
	{
		return 0;
	}
	Resources::load();
	sflogic();
	return 0;
}