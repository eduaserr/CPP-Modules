/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:18:43 by eduaserr          #+#    #+#             */
/*   Updated: 2025/07/28 19:03:33 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

namespace getStdin {
	void	print_param(char **av)
	{
		int	i = 0;

		while (av && av[++i])
			cout << av[i] << ' ';
		cout << endl;
	}

	void	ft_toupper(char *av)
	{	
		for (int j = 0; av[j]; ++j) {
			if (av[j] >= 'a' && av[j] <= 'z')
	 			cout << ((char)(av[j] - 32));
			else
				cout << av[j];
		}
		cout << ' ';
	}

	void	modify_param(char **av)
	{
		for (int i = 0; av && av[++i];)
			ft_toupper(av[i]);
		cout << endl;
	}
}

int	main(int ac, char **av)
{
	//coger parametros
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	else
		getStdin::modify_param(av);
	return (0);
}
