/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:36:13 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 22:27:14 by eduaserr         ###   ########.fr       */
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
	int	len = input.length();

	if (input[0] == ' ' || input[len - 1] == ' ')
		return (0);
	while (input[++i]){
		if (!isalpha(input[i]) && input[i] != ' ')
			return (0);
		if (input[i] == ' ' && input[i + 1] == ' ')
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
			std::cout << "Invalid input, only characters separated by one space allowed" << std::endl;
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

std::string PhoneBook::_truncateString(const std::string& str) const
{
	if (str.length() > 9)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::_showInfoContact(int index){
	std::cout << "\n=== CONTACT DETAILS ===" << std::endl;
	std::cout << "- First Name:	" << people[index - 1].getFirstName() << std::endl;
	std::cout << "- Last Name:	" << people[index - 1].getLastName() << std::endl;
	std::cout << "- Nickname:	" << people[index - 1].getNickname() << std::endl;
	std::cout << "- Phone:	" << people[index - 1].getNumber() << std::endl;
	std::cout << "- Secret:	" << people[index - 1].getSecret() << "\n" << std::endl;
}

void PhoneBook::_getContactIndex(void){
	std::string	index;

	while (true) {
		std::cout << "\n\nmore info, enter index: " << std::flush;
		if (!std::getline(std::cin, index, '\n'))
				exitPB();
		if (index.empty() || !std::cin.good())
			continue ;
		if (index.length() != 1){
			std::cout << "Enter only 1 digit" << std::endl;
			continue ;
		}
		int intIndex = index[0] - '0';
		if (!isdigit(index[0]) || intIndex < 1 || intIndex > totalContacts){
			std::cout << "introduce only 1 index from 1 to " << totalContacts << std::endl;
		}
		else {
			_showInfoContact(intIndex);
			break ;
		}
	}
}

void	PhoneBook::searchContact(void)
{
	if (totalContacts == 0)
	{
		std::cout << "\nNo contacts available.\n" << std::endl;
		return ;
	}
	std::cout << "\n	=== CONTACT LIST ===" << std::endl;
	std::cout << std::setw(6) << "Index" << " |";
	std::cout << std::setw(11) << "First Name" << " |";
	std::cout << std::setw(10) << "Last Name" << " |";
	std::cout << std::setw(9) << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;
	for (int i = 0; i < totalContacts; i++) {
		std::cout << std::setw(6) << i + 1 << " |";
		std::cout << std::setw(11) << _truncateString(people[i].getFirstName()) << " |";
		std::cout << std::setw(10) << _truncateString(people[i].getLastName()) << " |";
		std::cout << std::setw(9) << _truncateString(people[i].getNickname()) << std::endl;
	}
	_getContactIndex();
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
	people[index] = newContact;
	index = (index + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
	std::cout << "\nContact added succesfully!\n" << std::endl;
}
