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

void BitcoinExchange::validateFormat(const std::string& line, size_t pos) const {
	if (line.find('|', pos + 1) != std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);
	if (line[0] == ' ' || line[line.size() - 1] == ' ')
		throw std::runtime_error("Error: bad input => " + line);
	if (pos == 0 || pos == line.size() - 1)
		throw std::runtime_error("Error: bad input => " + line);
	if (line[pos - 1] != ' ' || line[pos + 1] != ' ')
		throw std::runtime_error("Error: bad input => " + line);
}

bool BitcoinExchange::checkDate(int year, int month, int day) const
{
	if (month < 1 || month > 12)						//check month
		return false;
	if (day < 1)										//check day
		return false;

	int days[] = {
		31,28,31,30,31,30,
		31,31,30,31,30,31
	};
	bool leap =											//leap year
		(year % 4 == 0 && year % 100 != 0) ||
		(year % 400 == 0);

	if (leap)
		days[1] = 29;
	if (day > days[month - 1])
		return false;
	return true;
}

void BitcoinExchange::validateDate(const std::string& line) const {
	if (line.empty())
		throw std::runtime_error("Error: bad input => " + line);
	if (line[0] == ' ' || line[line.size() - 1] == ' ')
		throw std::runtime_error("Error: bad input => " + line);
	if (line.size() != 10)
		throw std::runtime_error("Error: bad input => " + line);
	if (line[4] != '-' || line[7] != '-')
		throw std::runtime_error("Error: bad input => " + line);
	for (size_t i = 0; i < line.size(); i++) {
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(line[i]))
			throw std::runtime_error("Error: bad input => " + line);
	}
	int year = std::atoi(line.substr(0,4).c_str());
	int month = std::atoi(line.substr(5,2).c_str());
	int day = std::atoi(line.substr(8,2).c_str());

	if (!checkDate(year, month, day))
		throw std::runtime_error("Error: bad input => " + line);

}
void BitcoinExchange::validateValue(const std::string& line) const {
	if (line.empty())
		throw std::runtime_error("Error: bad input => " + line);
	if (line[0] == ' ' || line[line.size() - 1] == ' ')
		throw std::runtime_error("Error: bad input => " + line);

	char *end;
	double value = std::strtod(line.c_str(), &end);
	if (*end != '\0')
		throw std::runtime_error("Error: bad input => " + line);

	if (value > 1000)
		throw std::runtime_error("Error: too large number.");
	if (value < 0)
		throw std::runtime_error("Error: not a positive a number.");
}
double BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it;
	it = _database.lower_bound(date);
	// 1. La fecha es mayor que todas las de la base de datos.
	if (it == _database.end())
	{
		--it;
		return it->second;
	}

	// 2. La fecha existe exactamente.
	if (it->first == date)
		return it->second;

	// 3. La fecha es anterior a la primera de la base de datos.
	if (it == _database.begin())
		throw std::runtime_error("Error: no exchange rate available.");

	// 4. La fecha está entre dos fechas.
	--it;
	return it->second;
}

void BitcoinExchange::parseLine(const std::string& line)
{
	size_t pos = line.find('|');
	if (pos == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);

	validateFormat(line, pos);

	std::string date;
	date = line.substr(0, pos - 1);
	validateDate(date);

	std::string value;
	value = line.substr(pos + 2);
	validateValue(value);

	std::cout << "date is " << date << " | value is " << value << std::endl;

	printExchange(date, value);
}
void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string line;

	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty file.");
	if (line != "date | value")
		throw std::runtime_error("Invalid first line. Expected 'date | value'.");
	
	while (std::getline(file, line))
	{
		try {
			parseLine(line);
		}
		catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		}
	}

}
void BitcoinExchange::printExchange(const std::string& date, const std::string& value) const{
	double amount = std::strtod(value.c_str(), NULL);
	double rate = getExchangeRate(date);

	std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
}

void BitcoinExchange::printDatabase() const
{
	std::map<std::string, double>::const_iterator it;

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

	std::getline(file, line);
	while (std::getline(file, line))
	{
		pos = line.find(',');
		date = line.substr(0, pos);
		price = line.substr(pos + 1);
		value = std::atof(price.c_str());
		_database[date] = value;
	}
	//printDatabase();
}
