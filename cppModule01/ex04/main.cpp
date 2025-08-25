/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:48:08 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/25 21:20:29 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	replacestr(std::string& buff, char *s1, char *s2)
{
	(void)s2;
	if (buff.compare(s1) == 0){
		std::cout << "replace" << std::endl;
	}
	//	buff.replace();
}

static bool	createFilename(std::ifstream& ifd, char **av)
{
	std::ofstream	ofd("newFilename.txt");

	if (!ofd.is_open())
		return 1;
	std::string buff;
	while (std::getline(ifd, buff, '\n')){
		replacestr(buff, av[2], av[3]);
		ofd << buff << std::endl;}
	ofd.close();
	return (0);
}

bool	openFilename(const char *filename, std::ifstream& ifd)
{
	ifd.open(filename, std::ios::in);
	if (!ifd.is_open())
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	std::ifstream	ifd;

	if (ac == 4)
	{
		if (openFilename(av[1], ifd))
			std::cout << "error opening filename: " << av[1] << " does not exist" << std::endl;
		if (createFilename(ifd, av))
			std::cout << "error creating new file" << std::endl;
		ifd.close();
	}
	else
		std::cout << "invalid arguments" << std::endl;
	return 0;
}
