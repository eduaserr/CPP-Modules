#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& data) { (void)data; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& data) { (void)data; return *this; }
ScalarConverter::~ScalarConverter() {}

static int getType(const std::string& literal)
{
	if (literal.size() == 1 &&
		!std::isdigit(static_cast<unsigned char>(literal[0])))
		return 0; // char
	if (literal == "nan" || literal == "inf" ||
		literal == "+inf" || literal == "-inf")
		return 3; // double
	if (literal == "nanf" || literal == "inff" ||
		literal == "+inff" || literal == "-inff")
		return 2; // float

	if (literal.find('.') != std::string::npos)
	{
		if (literal[literal.size() - 1] == 'f')
			return 2;
		return 3;
	}
	return 1; // int
}

static double stringToDouble(const std::string& literal) {
	std::stringstream ss(literal);
	double d;
	ss >> d;
	return d;
}

char ScalarConverter::toChar(double d) {
	if (std::isnan(d) || std::isinf(d))
		return '\0';
	if (d < 0 || d > 127)
		return '\0';
	char c = static_cast<char>(d);
	if (!std::isprint(c))
		return '\0';
	return c;
}

int ScalarConverter::toInt(double d) {
	if (std::isnan(d) || std::isinf(d))
		return INT_MIN;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		return INT_MIN;
	return static_cast<int>(d);
}

float ScalarConverter::toFloat(double d) {
	return static_cast<float>(d);
}

double ScalarConverter::toDouble(double d) {
	return d;
}

void ScalarConverter::convert(const std::string& literal){
	int type = getType(literal);
	double d;

		try {
		if (type == 0) {
			d = static_cast<double>(literal[0]);
		} else if (type == 1 || type == 2 || type == 3) {
			d = stringToDouble(literal);
		}
	} catch (...) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	// char
	char c = toChar(d);
	if (c == '\0' && (std::isnan(d) || std::isinf(d) || d < 0 || d > 127))
		std::cout << "char: impossible\n";
	else if (c == '\0')
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";

	// int
	int i = toInt(d);
	if (i == INT_MIN && (std::isnan(d) || std::isinf(d)))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << "\n";

	// float
	float f = toFloat(d);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";

	// double
	double dbl = toDouble(d);
	std::cout << "double: " << dbl << "\n";
}
