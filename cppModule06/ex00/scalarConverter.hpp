#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <limits>




class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& data);
	ScalarConverter& operator=(const ScalarConverter& data);
	~ScalarConverter();

	static char toChar(double d);
	static int toInt(double d);
	static float toFloat(double d);
	static double toDouble(double d);
public:
	static void convert(const std::string& literal);
};

#endif