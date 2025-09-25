/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:17:58 by eduaserr          #+#    #+#             */
/*   Updated: 2025/09/25 16:47:03 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int	Fixed::_fracBits = 8;

Fixed::Fixed():_fptrNumberValue(0){
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& data){
	std::cout << "Copy constructor called" << std::endl;
	*this = data;
}
Fixed::Fixed(const int number){
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float number){
	std::cout << "Float constructor called" << std::endl;
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

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fptrNumberValue);
}

void	Fixed::setRawBits(int const raw){
	this->_fptrNumberValue = raw;
}