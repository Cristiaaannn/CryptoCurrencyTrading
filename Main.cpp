#include<iostream>
#include "Headers.h"

int main()
{
	showMenu();
	int userOption{ 99 };
	while (userOption != 0) {
	std::cin >> userOption;
		switch (userOption)
		{
		case 0:
			std::cout << "Bye" << std::endl;
			break;
		case 1:
			PrintHelp();
			showMenu();
			break;
		case 2:
			PrintStats();
			showMenu();
			break;
		case 3:
			PlaceAsk();
			showMenu();
			break;
		case 4:
			PlaceBid();
			showMenu();
			break;
		case 5:
			PrintWallet();
			showMenu();
			break;
		case 6:
			NextTimeStamp();
			showMenu();
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			showMenu();
			break;
		}
	}
	return 0;
}