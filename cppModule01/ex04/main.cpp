/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:48:08 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/26 21:33:42 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/createFile.hpp"

Main::Main(){}
Main::~Main(){}

bool	openFilename(const char *filename, std::ifstream& ifd)
{
	ifd.open(filename, std::ios::in);
	if (!ifd.is_open())
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	Main	fd;

	if (ac == 4)
	{
		if (openFilename(av[1], fd.ifd))
			std::cout << "error opening filename: " << av[1] << " does not exist" << std::endl;
		if (!fd.ifd || fd.createFilename(fd.ifd, av))
			std::cout << "error creating new file" << std::endl;
		fd.ifd.close();
	}
	else
		std::cout << "invalid arguments" << std::endl;
	return 0;
}
