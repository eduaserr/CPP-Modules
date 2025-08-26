/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:48:08 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/26 21:54:45 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/createFile.hpp"

Main::Main(){}
Main::~Main(){}

int main(int ac, char **av)
{
	Main	fd;

	if (ac == 4)
	{
		if (fd.openFilename(av[1]))
			std::cout << "error opening filename: " << av[1] << " does not exist" << std::endl;
		if (!fd.isFileOpen() || fd.createFilename(av))
			std::cout << "error creating new file" << std::endl;
		fd.closeFd();
	}
	else
		std::cout << "invalid arguments" << std::endl;
	return 0;
}
