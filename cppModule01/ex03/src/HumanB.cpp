/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:51:27 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/14 03:21:52 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(){
	_weapon = NULL;
}

HumanB::HumanB(std::string name){// cambiarlista de inicializacion
	_weapon = NULL;
	_name = name;
}

HumanB::~HumanB(){}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
