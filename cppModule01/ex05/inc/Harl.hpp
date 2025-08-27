/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:58:00 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/27 19:35:10 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

class	Harl
{
	private :
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public :
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif