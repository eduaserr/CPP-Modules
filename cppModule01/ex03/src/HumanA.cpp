/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:51:23 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/14 03:21:41 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) // cambiarlista de inicializacion
{
	this->_name = name;
	this->_weapon = weapon;
}
//HumanA::HumanA(){}
HumanA::~HumanA(){}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
