/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:17:58 by eduaserr          #+#    #+#             */
/*   Updated: 2025/09/25 18:25:05 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int	Fixed::_fracBits = 8;

Fixed::Fixed():_fpNumberValue(0){
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& data){
	std::cout << "Copy constructor called" << std::endl;
	*this = data;
}
Fixed::Fixed(const int number){
	std::cout << "Int constructor called" << std::endl;
	_fpNumberValue = number << _fracBits;						// Multiplica por 2^8 = 256
}
Fixed::Fixed(const float number){
	std::cout << "Float constructor called" << std::endl;
	_fpNumberValue = (int)roundf(number * (1 << _fracBits));	// Multiplica por 256 y redondea
}

Fixed	&Fixed::operator=(const Fixed& data){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &data)
		this->setRawBits(data.getRawBits());
	return (*this);
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt( void ) const {
	return (_fpNumberValue >> _fracBits);
}
float	Fixed::toFloat( void ) const {
	return ((float)_fpNumberValue / (1 << _fracBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

int	Fixed::getRawBits() const {
	return (this->_fpNumberValue);
}
void	Fixed::setRawBits(int const raw){
	this->_fpNumberValue = raw;
}