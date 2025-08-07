/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:36:13 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 16:03:18 by eduaserr         ###   ########.fr       */
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
			exitPB();
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
{
	if (totalContacts == 0)
	{
		std::cout << "\nNo contacts available." << std::endl;
		return ;
	}
	std::cout << "\n	=== CONTACT LIST ===" << std::endl;
	std::cout << std::setw(6) << "Index" << " |";
	std::cout << std::setw(11) << "First Name" << " |";
	std::cout << std::setw(10) << "Last Name" << " |";
	std::cout << std::setw(9) << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;
	for (int i = 0; i < totalContacts; i++) { // subject chequear minimo de espacio
		std::cout << std::setw(6) << i << " |";
		std::cout << std::setw(11) << people[i].getFirstName() << " |";
		std::cout << std::setw(10) << people[i].getLastName() << " |";
		std::cout << std::setw(9) << people[i].getNickname() << std::endl;
	}
}

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

	//for (int i = std::min(totalContacts, 7); i > 0; i--){
	//people[i] = people[i-1];
	//}
	//people[0] = newContact;

	people[index] = newContact;
	index = (index + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
	std::cout << "\nContact added succesfully!\n" << std::endl;
}
