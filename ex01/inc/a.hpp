/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:55:04 by eduaserr          #+#    #+#             */
/*   Updated: 2025/07/30 23:05:17 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H
# define A_H

#include <iostream>
#include <string>

class People{
	public :
		std::string firstName;
		std::string	lastName;
		std::string	age;
		std::string	phrase;
		People(void);
		void	Parse(void);
		~People(void);
};
#endif