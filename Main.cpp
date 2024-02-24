#include<iostream>
#include "Headers.h"

int main()
{
	while (true)
	{
		ShowMenu();
		int userOption = GetUserOption();
		if (userOption == 0)
		{
			std::cout << "Bye" << std::endl;
			break;
		}
		ProcessUserOption(userOption);
	}
	return 0;
}