#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <literal>\n";
		return 1;
	}

	ScalarConverter::convert(av[1]);
	return 0;
}

    // ./scalarConverter 42
    // ./scalarConverter 0
    // ./scalarConverter -42
    // ./scalarConverter a
    // ./scalarConverter '*'
    // ./scalarConverter 0.0f
    // ./scalarConverter 4.2f
    // ./scalarConverter -4.2f
    // ./scalarConverter 4.242
    // ./scalarConverter 0.0
    // ./scalarConverter -4.2
    // ./scalarConverter inf
    // ./scalarConverter -inf
    // ./scalarConverter nan
    // ./scalarConverter inff
    // ./scalarConverter -inff
    // ./scalarConverter nanf