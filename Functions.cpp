#include<iostream>
#include "Headers.h"

void showMenu()
{
	std::cout << std::endl;
	std::cout << "0: Exit " << std::endl;
	std::cout << "1: Print help " << std::endl;
	std::cout << "2: Print exchange stats " << std::endl;
	std::cout << "3: Place an ask " << std::endl;
	std::cout << "4: Place a bid " << std::endl;
	std::cout << "5: Print wallet " << std::endl;
	std::cout << "6: Continue (next timestamp) " << std::endl;
	std::cout << "===========================" << std::endl;
	std::cout << "Type in 1-6" << std::endl;
}

void PrintHelp()
{
	std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl;
}

void PrintStats()
{
	std::cout << "Market looks good" << std::endl;
}

void PlaceAsk()
{
	std::cout << "Make an offer" << std::endl;
}

void PlaceBid()
{
	std::cout << "Make a bid - enter the amount" << std::endl;
}

void PrintWallet()
{
	std::cout << "Your wallet is empty" << std::endl;
}

void NextTimeStamp()
{
	std::cout << "Going to the next transaction" << std::endl;
}
