/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:13:03 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 22:08:15 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private :
		Contact	people[8];
		int		index;
		int		totalContacts;
		int		_checkAlpha(std::string& input);
		int		_checkNumber(std::string& input);
		void	_getInput(std::string& input, std::string msg);
		void	_getNumber(std::string& number, std::string msg);
		std::string	_truncateString(const std::string& str) const;
		void	_showInfoContact(int index);
	public :
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void);
		void	exitPB(void);
};
#endif