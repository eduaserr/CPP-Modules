/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:17:58 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/26 23:19:55 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/createFile.hpp"

static void	replacestr(std::string& buff, std::string s1, std::string s2)
{
	std::string	pre;
	std::string	pos;
	int			ix;
	while (buff.find(s1) != std::string::npos){
		ix = buff.find(s1);
		pre = buff.substr(0, ix);
		pre.append(s2);
		pos = buff.substr(ix + s1.size(), buff.size());
		buff = pre + pos;
		std::cout << "Reemplazando coincidencia en posición: " << ix << std::endl;
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