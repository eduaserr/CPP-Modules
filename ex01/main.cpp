/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:25:39 by eduaserr          #+#    #+#             */
/*   Updated: 2025/07/30 23:05:12 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/a.hpp"

People::People(void){
	std::cout << "Hey" << std::endl;
}

void	People::Parse(void){
	std::cout << "Hola" << std::endl;
}

People::~People(void){
	std::cout << "Adios" << std::endl;
}

int	main(void)
{
	People obj;
	std::cout << "hello" << std::endl;
	return (0);
}
