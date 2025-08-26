/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:58:00 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/26 21:27:47 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATEFILE_HPP
# define CREATEFILE_HPP

#include <iostream>
#include <string>
#include <fstream>

class	Main
{
	private :
		

	public :
		std::ifstream	ifd;
		std::string	buff;
		Main();
		~Main();
		bool	createFilename(std::ifstream& ifd, char **av);
};

#endif