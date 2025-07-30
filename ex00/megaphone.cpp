/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:18:43 by eduaserr          #+#    #+#             */
/*   Updated: 2025/07/30 20:27:42 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	modify_param(char **av)
{
	for (int i = 0; av && av[++i];){
		for (int j = 0; av[i][j]; ++j) {
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
 				std::cout << ((char)(av[i][j] - 32));
			else
				std::cout << av[i][j];
	}
	std::cout << ' ';
	}
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	//coger parametros
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		modify_param(av);
	return (0);
}
