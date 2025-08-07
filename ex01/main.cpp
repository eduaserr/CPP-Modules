/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:25:39 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 23:16:44 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Phonebook.hpp"

int	main(void)
{
	PhoneBook	phbook;
	std::string	cmd;

	while (cmd != "EXIT"){
		std::cout << "[ SELECT ANY OPTION ]\n\n> ADD\n> SEARCH\n> EXIT" << std::endl;
		if (!std::getline(std::cin, cmd, '\n'))
    		phbook.exitPB();
		if (std::cin.good()){
			if (cmd == "ADD"){phbook.addContact();}
			else if (cmd == "SEARCH"){phbook.searchContact();}
			else if (cmd == "EXIT"){phbook.exitPB();}
			else
				std::cout << "\nInvalid option\n" << std::endl;
			std::cin.clear();
		}
		else
			break ;
	}
	return (0);
}
