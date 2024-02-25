#include<iostream>
#include<iomanip>
#include<fstream>
#include <regex>
#include "MerkelMain.h"

void MerkelMain::init()
{

	LoadOrderBook();
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
}

void MerkelMain::LoadOrderBook()
{
	int lineNumber{ 0 };
	std::ifstream csvFile{ "Data.csv" };
	std::string line;
	std::vector<std::string> tokens;
	if (csvFile.is_open())
	{
		std::cout << "File opened" << std::endl;
		while (std::getline(csvFile, line))
		{
			++lineNumber;
			tokens = Tokenise(line, ',');
			if (tokens.size() != 5)
			{
				if (line.length() == 0)
				{
					std::cout << "Empty line detected  - " << lineNumber << std::endl;
					continue;
				}
				else
				{
					std::cout << "Bad line - " << lineNumber << std::endl;
					continue;
				}
			}

			try {
				std::regex r("[^0-9.]+");
				if (std::regex_search(tokens[3], r) || std::regex_search(tokens[4], r)) {
					throw std::invalid_argument(""); // Non-numeric character found
				}
				double price = std::stod(tokens[3]);
				double amount = std::stod(tokens[4]);
				OrderBookType type;
				if (tokens.at(2) == "Bid")
				{
					type = OrderBookType::bid;
				}
				else
				{
					type = OrderBookType::ask;
				}
				OrderBookEntry newOrder{ price,amount,tokens.at(0),tokens.at(1), type };
				orders.push_back(newOrder);
			}
			catch (std::exception& e)
			{
				std::cout << "Bad float! " << lineNumber << std::endl;
				break;
			}
		}
		csvFile.close();
	}
	else
	{
		std::cout << "File not opened" << std::endl;
	}
}

std::vector<std::string> MerkelMain::Tokenise(std::string csvLine, char separator)
{
	std::vector<std::string> tokens;
	std::string token;
	signed int start, end;
	start = csvLine.find_first_not_of(separator, 0);
	do {
		end = csvLine.find_first_of(separator, start);
		if (start == csvLine.length() || start == end) break;
		if (end >= 0) token = csvLine.substr(start, end - start);
		else token = csvLine.substr(start, csvLine.length() - start);
		tokens.push_back(token);
		start = end + 1;
	} while (end != std::string::npos);
	return tokens;
}

void MerkelMain::ShowMenu()
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

void MerkelMain::ProcessUserOption(int option)
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

int MerkelMain::GetUserOption()
{
	int a;
	std::cout << "Enter an option: " << std::endl;
	std::cin >> a;
	return a;
}

void MerkelMain::PrintHelp()
{
	std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl;
}

void MerkelMain::PrintStats()
{
	std::cout << "Orderbook contains: " << orders.size() << " entries." << std::endl;
	std::cout << "The highest price is: " << std::fixed << std::setprecision(8) << ComputeHighPrice(orders) << std::endl;
	std::cout << "The lowest price is: " << ComputeLowPrice(orders) << std::endl;
	std::cout << "The average price is: " << std::fixed << std::setprecision(2) <<ComputeAveragePrice(orders) << std::endl;
	std::cout << "The price spread is: " << ComputePriceSpread(orders) << std::endl;
}

void MerkelMain::PlaceAsk()
{
	std::cout << "Make an offer" << std::endl;
}

void MerkelMain::PlaceBid()
{
	std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::PrintWallet()
{
	std::cout << "Your wallet is empty" << std::endl;
}

void MerkelMain::NextTimeStamp()
{
	std::cout << "Going to the next transaction" << std::endl;
}

double MerkelMain::ComputeAveragePrice(std::vector<OrderBookEntry>& entries)
{
	double sum = 0.0;
	for (OrderBookEntry& entry : entries)
	{
		sum += entry.price;
	}
	return sum / (double)entries.size();
}

double MerkelMain::ComputeLowPrice(std::vector<OrderBookEntry>& entries)
{
	double lowestValue{ DBL_MAX };
	for (OrderBookEntry& entry : entries)
	{
		if (entry.price < lowestValue)
			lowestValue = entry.price;
	}
	return lowestValue;
}

double MerkelMain::ComputeHighPrice(std::vector<OrderBookEntry>& entries)
{
	double highestValue = 0.0;
	for (OrderBookEntry& entry : entries)
	{
		if (entry.price > highestValue)
			highestValue = entry.price;
	}
	return highestValue;
}

double MerkelMain::ComputePriceSpread(std::vector<OrderBookEntry>& entries)
{
	return ComputeHighPrice(entries) - ComputeLowPrice(entries);
}

std::string MerkelMain::GetOrderType(OrderBookEntry& entry)
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
