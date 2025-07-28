/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:18:43 by eduaserr          #+#    #+#             */
/*   Updated: 2025/07/28 04:00:57 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

namespace getStdin {
	void	print_param(char **av)
	{
		int	i = 0;

		while (av && av[++i])
			cout << av[i] << ' ';
		cout << endl;
	}
	
	char	ft_toupper(char **av, int i)
	{	
		for (int j = 0; av[i][j]; ++j) {
    	char c = av[i][j];
    	if (c >= 'a' && c <= 'z')
        return ((char)(c - 32));
    	else
    	   return c;
		}
		return (0);
	}
	
	void	modify_param(char **av)
	{
		int	i = 0;
	
		while (av && av[++i])
			cout << ft_toupper(av, i) << ' ';
		cout << endl;
	}
}

int	main(int ac, char **av)
{
	//coger parametros
	getStdin::modify_param(av);
	return (0);
}
