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
	std::map<std::string, double> _database;

	void loadDatabase();

	void validateFormat(const std::string& line, size_t pos) const;
	void parseLine(const std::string& line);
	bool checkDate(int year, int month, int day) const;
	void validateDate(const std::string& date) const;
	void validateValue(const std::string& value) const;

	void printExchange(const std::string& date, const std::string& value) const;
	double getExchangeRate(const std::string& date) const;


public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void processInput(const std::string& filename);
	void printDatabase() const;


};

#endif