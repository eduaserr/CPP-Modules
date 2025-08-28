/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:58:00 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/28 20:52:54 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
	private :
		int					_fptrNumberValue;
		static const int	_fracBits;
	public :
		Fixed();
		Fixed(Fixed& data);
		Fixed& operator=(Fixed& data);
		~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif