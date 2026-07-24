#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	loadDatabase();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_database = other._database;
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string line;

	while (std::getline(file, line))
	{
		//std::cout << line << std::endl;
	}
}

void BitcoinExchange::printDatabase() const
{
	std::map<std::string, float>::const_iterator it;

	for (it = _database.begin(); it != _database.end(); ++it) {
		std::cout << it->first << " -> " << it->second << std::endl;
	}
}

void BitcoinExchange::loadDatabase()
{
	std::ifstream file("data.csv");

	if (!file)
		throw std::runtime_error("Error: could not open data.csv");

	std::string line;
	size_t pos;
	std::string date;
	std::string price;
	float value;

	while (std::getline(file, line))
	{
		pos = line.find(',');
		date = line.substr(0, pos);
		price = line.substr(pos + 1);
		value = std::atof(price.c_str());
		_database[date] = value;
	}
	printDatabase();
}
