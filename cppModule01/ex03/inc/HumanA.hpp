/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:51:25 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/12 20:36:27 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <Weapon.hpp>

class	HumanA
{
	private:
		Weapon gun;
		std::string _name;
	public:
		HumanA();
		HumanA(std::string name, Weapon weapon);
		//HumanA HumanA::operator=(HumanA &other);
		~HumanA();
};

#endif