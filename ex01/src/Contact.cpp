/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:57:19 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 02:35:33 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

void	Contact::setContact(std::string firstName, std::string lastName,
						std::string nickname, std::string number,
						std::string secret)
						{
						    this->_firstName = firstName;
							this->_lastName = lastName;
							this->_nickname = nickname;
							this->_number = number;
							this->_secret = secret;
						}

std::string Contact::getFirstName(void) { return _firstName; }
std::string Contact::getLastName(void) { return _lastName; }
std::string Contact::getNickname(void) { return _nickname; }
std::string Contact::getNumber(void) { return _number; }
std::string Contact::getSecret(void) { return _secret; }