#include<iostream>
#include "Headers.h"

void ShowMenu()
{
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

void ProcessUserOption(int option)
{
	switch (option)
	{
	case 1:
		PrintHelp();
		break;
	case 2:
		PrintStats();
		break;
	case 3:
		PlaceAsk();
		break;
	case 4:
		PlaceBid();
		break;
	case 5:
		PrintWallet();
		break;
	case 6:
		NextTimeStamp();
		break;
	default:
		std::cout << "Invalid input" << std::endl;
		break;
	}
}

int GetUserOption()
{
	int a;
	std::cout << "Enter an option: " << std::endl;
	std::cin >> a;
	return a;
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

double ComputeAveragePrice(std::vector<OrderBookEntry>& entries)
{
	double sum{ 0 };
	for (OrderBookEntry& entry : entries)
	{
		sum += entry.price;
	}
	return sum / (double)entries.size();
}

double ComputeLowPrice(std::vector<OrderBookEntry>& entries)
{
	double lowestValue{ DBL_MAX };
	for (OrderBookEntry& entry : entries)
	{
		if (entry.price < lowestValue)
			lowestValue = entry.price;
	}
	return lowestValue;
}

double ComputeHighPrice(std::vector<OrderBookEntry>& entries)
{
	double highestValue{ 0 };
	for (OrderBookEntry& entry : entries)
	{
		if (entry.price > highestValue)
			highestValue = entry.price;
	}
	return highestValue;
}

double ComputePriceSpread(std::vector<OrderBookEntry>& entries)
{
	return ComputeHighPrice(entries) - ComputeLowPrice(entries);
}

std::string GetOrderType(OrderBookEntry& entry)
{
	switch (entry.orderType)
	{
	case OrderBookType::bid:
		return "bid";
	case OrderBookType::ask:
		return "ask";
	default:
		break;
	}
}