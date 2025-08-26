/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:48:08 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/27 00:34:01 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Harl.hpp"

int	main()
{
	std::string	level;
	if (!std::getline(std::cin, level))
		exit(0);
	if (level == "DEBUG")
		std::cout << "in DEBUG" << std::endl;
	if (level == "INFO")
		std::cout << "in INFO" << std::endl;
	if (level == "WARNING")
		std::cout << "in WARNING" << std::endl;
	if (level == "ERROR")
		std::cout << "in ERROR" << std::endl;
	return (0);
}