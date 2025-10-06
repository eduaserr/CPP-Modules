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
}
Fixed::Fixed(const Fixed& data) : _fpNumberValue(data._fpNumberValue){
}
Fixed	&Fixed::operator=(const Fixed& data){
	if (this != &data)
		this->setRawBits(data.getRawBits());
	return (*this);
}
Fixed::Fixed(const int number){
	_fpNumberValue = number << _fracBits;						// Multiplica por 2^8 = 256
}
Fixed::Fixed(const float number){
	_fpNumberValue = (int)roundf(number * (1 << _fracBits));	// Multiplica por 256 y redondea
}

Fixed::~Fixed(){
}

int	Fixed::toInt( void ) const {
	return (_fpNumberValue >> _fracBits);
}
float	Fixed::toFloat( void ) const {
	return ((float)_fpNumberValue / (1 << _fracBits));
}

int	Fixed::getRawBits() const {
	return (this->_fpNumberValue);
}
void	Fixed::setRawBits(int const raw){
	this->_fpNumberValue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

bool	Fixed::operator<(const Fixed& other) const {
	return (this->_fpNumberValue < other._fpNumberValue);
}
bool	Fixed::operator<=(const Fixed& other) const {
	return (this->_fpNumberValue <= other._fpNumberValue);
}
bool	Fixed::operator>(const Fixed& other) const {
	return (this->_fpNumberValue > other._fpNumberValue);
}
bool	Fixed::operator>=(const Fixed& other) const {
	return (this->_fpNumberValue >= other._fpNumberValue);
}
bool	Fixed::operator==(const Fixed& other) const {
	return (this->_fpNumberValue == other._fpNumberValue);
}
bool	Fixed::operator!=(const Fixed& other) const {
	return (this->_fpNumberValue != other._fpNumberValue);
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	obj;
	obj.setRawBits(this->_fpNumberValue + other._fpNumberValue);
	return (obj);
}
Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed	obj;
	obj.setRawBits(this->_fpNumberValue - other._fpNumberValue);
	return (obj);
}
Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	obj;
	obj.setRawBits((this->_fpNumberValue * other._fpNumberValue) >> _fracBits);
	return (obj);
}
Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed	obj;
	obj.setRawBits((this->_fpNumberValue << _fracBits) / other._fpNumberValue);
	return (obj);
}

Fixed& Fixed::operator++() {
	++this->_fpNumberValue;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++this->_fpNumberValue;
	return (tmp);
}
Fixed& Fixed::operator--() {
	--this->_fpNumberValue;
	return (*this);
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--this->_fpNumberValue;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}
