/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:57:19 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/07 18:22:48 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

void	Contact::setContact(const std::string& firstName, const std::string& lastName,
						const std::string& nickname, const std::string& number,
						const std::string& secret)
						{
							_firstName = firstName;
							_lastName = lastName;
							_nickname = nickname;
							_number = number;
							_secret = secret;
						}

std::string	Contact::getFirstName(void) { return _firstName; }
std::string	Contact::getLastName(void) { return _lastName; }
std::string	Contact::getNickname(void) { return _nickname; }
std::string	Contact::getNumber(void) { return _number; }
std::string	Contact::getSecret(void) { return _secret; }
