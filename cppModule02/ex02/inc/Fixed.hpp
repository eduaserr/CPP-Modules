#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	private :
		int					_fpNumberValue;
		static const int	_fracBits;
	public :
		// constructor / destructor
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int number);
		Fixed(const float number);
		Fixed& operator=(const Fixed& data);
		~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// operadores de comparacion
	bool	operator<(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	// operadores aritmeticos
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	// operadores de incremento
	Fixed&	operator++();	
	Fixed	operator++(int);
	Fixed&	operator--();	
	Fixed	operator--(int);

	// funciones estáticas
	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif