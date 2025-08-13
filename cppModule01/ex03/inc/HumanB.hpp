/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:51:30 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/13 20:01:35 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon _weapon;
		std::string _name;
	public:
		HumanB();
		HumanB(std::string name);
		//HumanA HumanA::operator=(HumanA &other);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon weapon);
};

#endif