/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:48:08 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/11 01:53:57 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		data = "THIS IS BRAIN";
	std::string*	PTR = &data;
	std::string&	REF = data;

	std::cout << &data << std::endl;
	std::cout << PTR << std::endl;
	std::cout << &REF << "\n" << std::endl;
	std::cout << data << std::endl;
	std::cout << *PTR << std::endl;
	std::cout << REF << std::endl;
	return (0);
}
