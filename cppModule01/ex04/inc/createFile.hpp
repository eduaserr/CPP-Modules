/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:58:00 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/26 21:55:31 by eduaserr         ###   ########.fr       */
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
		std::ifstream	ifd;
		std::string	buff;

	public :
		Main();
		~Main();
		bool	isFileOpen() const {return ifd.is_open();}
		void	closeFd() {ifd.close();}
		bool	createFilename(char **av);
		bool	openFilename(const char *filename);
};

#endif