/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:55:04 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/06 23:13:39 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>

class Contact{
	private :
		void	Parse(void);
		std::string _firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;
	public :
		Contact(void);
		~Contact(void);
		std::string	getFirstName(void);
		void	getName(void);
};
#endif