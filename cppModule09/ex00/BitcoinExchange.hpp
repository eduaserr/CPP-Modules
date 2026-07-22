#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <string>
#include <stdlib.h>

class BitcoinExchange
{
private:
	std::map<std::string, float> _database;

	void loadDatabase();

	//bool validateFormat(const std::string& line) const;
	//bool validateDate(const std::string& date) const;
	//bool validateValue(const std::string& value) const;

	//float getExchangeRate(const std::string& date) const;


public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void processInput(const std::string& filename);
	void printDatabase() const;


};

#endif