#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
public:

	/// <summary>
	/// Starting the app
	/// </summary>
	void init();

private:
	/// <summary>
	/// The app main orders
	/// </summary>
	std::vector<OrderBookEntry> orders;

	/// <summary>
	/// Tokenises a source
	/// </summary>
	/// <param name="csvLine">string to be tokenised</param>
	/// <param name="separator">token separator</param>
	/// <returns>vector of tokens</returns>
	std::vector<std::string> Tokenise(std::string csvLine, char separator);

	/// <summary>
	/// Loads the Order Book data
	/// </summary>
	void LoadOrderBook();

	/// <summary>
	/// Prints the market stats
	/// </summary>
	void printMarketStats();

	/// <summary>
	/// Processes the user option
	/// </summary>
	/// <param name="option">int according to the option</param>
	void ProcessUserOption(int option);

	/// <summary>
	/// Gets the option from the user
	/// </summary>
	/// <returns>The option in int format</returns>
	int GetUserOption();

	/// <summary>
	/// Prints the menu
	/// </summary>
	void ShowMenu();

	/// <summary>
	/// Prints the help context
	/// </summary>
	void PrintHelp();

	/// <summary>
	/// Prints the stats context
	/// </summary>
	void PrintStats();

	/// <summary>
	/// Place an ask (offer)
	/// </summary>
	void PlaceAsk();

	/// <summary>
	/// Place a bid
	/// </summary>
	void PlaceBid();

	/// <summary>
	/// Printing wallet
	/// </summary>
	void PrintWallet();

	/// <summary>
	/// Next TimeStamp
	/// </summary>
	void NextTimeStamp();

	/// <summary>
	/// Computes the average price of the objects contained by the vector
	/// </summary>
	/// <param name="entries">Reference to the vector containing the objects</param>
	/// <returns>(double) The average price</returns>
	double ComputeAveragePrice(std::vector<OrderBookEntry>& entries);

	/// <summary>
	/// Computes the lowest price of the objects contained by the vector
	/// </summary>
	/// <param name="entries">Reference to the vector containing the objects</param>
	/// <returns>(double) The lowest price</returns>
	double ComputeLowPrice(std::vector<OrderBookEntry>& entries);

	/// <summary>
	/// Computes the highest price of the objects contained by the vector
	/// </summary>
	/// <param name="entries">Reference to the vector containing the objects</param>
	/// <returns>(double) The highest price</returns>
	double ComputeHighPrice(std::vector<OrderBookEntry>& entries);

	/// <summary>
	/// Computes the price spread of the objects contained by the vector
	/// </summary>
	/// <param name="entries">Reference to the vector containing the objects</param>
	/// <returns>(double) The price spread</returns>
	double ComputePriceSpread(std::vector<OrderBookEntry>& entries);

	/// <summary>
	/// Printable format of order type
	/// </summary>
	/// <param name="entry"></param>
	/// <returns>string of the order type</returns>
	std::string GetOrderType(OrderBookEntry& entry);
};