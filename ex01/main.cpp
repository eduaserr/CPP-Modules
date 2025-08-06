/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:25:39 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/06 23:43:08 by eduaserr         ###   ########.fr       */
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
	while (cmd != "EXIT"){
		if (!std::getline(std::cin, cmd, '\n'))
    		phbook.exitPB();
		if (std::cin.good()){
			if (cmd == "ADD"){phbook.addContact();}
			else if (cmd == "SEARCH"){phbook.searchContact();}
			else if (cmd == "EXIT"){phbook.exitPB();}
			else
				std::cout << "Invalid option" << std::endl;
			std::cin.clear();
		}
		else
			break ;
	}
	return (0);
}
