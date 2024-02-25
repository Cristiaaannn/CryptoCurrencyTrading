#pragma once
#include <string>
#include "OrderBookType.h"
class OrderBookEntry
{
public:

	OrderBookEntry(double price, double amount, std::string timeStamp, std::string product, OrderBookType orderType)
		:price(price),
		amount(amount),
		timeStamp(timeStamp),
		product(product),
		orderType(orderType)
	{

	}

	double price;
	double amount;
	std::string timeStamp;
	std::string product;
	OrderBookType orderType;
};