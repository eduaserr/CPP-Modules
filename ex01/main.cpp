/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:25:39 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/06 02:23:20 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Phonebook.hpp"

PhoneBook::PhoneBook(void) {}
PhoneBook::~PhoneBook(void) {}

Contact::Contact(void) {}
Contact::~Contact(void) {}

int	main(void)
{
	PhoneBook	phbook;
	std::string	cmd;

	std::cout << "[SELECT ANY OPTION]\n\n> ADD\n> SEARCH\n> EXIT" << std::endl;
	if (!std::getline(std::cin, cmd, '\n'))
    	return (0);
	while (cmd != "EXIT"){
		std::cout << "Has introducido: " << cmd << std::endl;
		std::cin.clear();
	}
	return (0);
}
