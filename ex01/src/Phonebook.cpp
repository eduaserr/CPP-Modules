/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:36:13 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 02:37:27 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

PhoneBook::PhoneBook(void) {
	index = 0;
	totalContacts = 0;
}
PhoneBook::~PhoneBook(void) {}

int		PhoneBook::_checkNumber(std::string& input)
{
	int	i = -1;

	while (input[++i]){
		if (!isdigit(input[i]))
			return (0);
	}
	if (i != 9)
		return (0);
	return (1);
}

int		PhoneBook::_checkAlpha(std::string& input)
{
	int	i = -1;

	while (input[++i]){
		if (!isalpha(input[i]))
			return (0);
	}
	return (1);
}

void	PhoneBook::_getInput(std::string& input, std::string msg)
{
	while (true){
		std::cout << msg << std::flush;
		if (!std::getline(std::cin, input, '\n'))
			exitPB();
		if (!input.empty() && std::cin.good() && _checkAlpha(input))
			return ;
		else
			std::cout << "Invalid input, only characters allowed" << std::endl;
	}
}
void	PhoneBook::_getNumber(std::string& input, std::string msg)
{
	while (true){
		std::cout << msg << std::flush;
		if (!std::getline(std::cin, input, '\n'))
			exit(0);
		if (!input.empty() && std::cin.good() && _checkNumber(input))
			return ;
		else
			std::cout << "Invalid input, only (9) numbers allowed" << std::endl;
	}
}
void	PhoneBook::exitPB(void)
{
	std::cout << std::endl << "Exit program ..." << std::endl;
	exit(0);
}

void	PhoneBook::searchContact(void)
{}

void	PhoneBook::addContact(void)
{
	std::string	firstName, lastName, nickname, number, secret;

	std::cout << "\n=== ADD NEW CONTACT ===" << std::endl;
	_getInput(firstName, "First Name: ");
	_getInput(lastName, "Last Name: ");
	_getInput(nickname, "Nickname: ");
	_getNumber(number, "Number phone: ");
	_getInput(secret, "Darkest secret: ");

	Contact	newContact;
	newContact.setContact(firstName, lastName, nickname, number, secret);
	people[index] = newContact;
	index = (index + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
	std::cout << "\nContact added succesfully!\n" << std::endl;
}
