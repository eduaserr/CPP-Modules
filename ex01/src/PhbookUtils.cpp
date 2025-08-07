/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhBookUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:50:54 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 22:52:32 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

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
