/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:17:58 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/26 21:42:59 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/createFile.hpp"

static void	replacestr(std::string& buff, std::string s1, std::string s2)
{
	std::string	pre;
	std::string	pos;
	int	ix = buff.find(s1);
	if (buff.find(s1) != std::string::npos){
		pre = buff.substr(0, ix);
		pre.append(s2);
		pos = buff.substr(ix + s1.size(), buff.size());
		buff = pre + pos;
	}
}

bool	Main::createFilename(char **av)
{
	std::ofstream	ofd("filename.replace");

	if (!ofd.is_open()){
		ifd.close();
		return 1;}
	while (std::getline(ifd, buff, '\n')){
		replacestr(buff, av[2], av[3]);
		ofd << buff;
		if (ifd.peek() != EOF)
			ofd << std::endl;
	}
	ofd.close();
	return (0);
}

bool	Main::openFilename(const char *filename)
{
	ifd.open(filename, std::ios::in);
	if (!ifd.is_open())
		return (1);
	return (0);
}