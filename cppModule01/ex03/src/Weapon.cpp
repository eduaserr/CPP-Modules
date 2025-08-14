/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:51:35 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/14 03:05:45 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

//Weapon::Weapon(){}
Weapon::Weapon(std::string type){
	this->_type = type;
}
Weapon::~Weapon(){}

std::string const	&Weapon::getType(void){
	return (this->_type);
}

void	Weapon::setType(std::string const &type){
	this->_type = type;
}
