/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:55:04 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 15:49:13 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <iomanip>

class Contact{
	private :

		std::string _firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;
	public :
		Contact(void);
		~Contact(void);
		void	setContact(const std::string& firstName, const std::string& lastName,
						const std::string& nickname, const std::string& number,
						const std::string& secret);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getNumber(void);
		std::string getSecret(void);
};
#endif