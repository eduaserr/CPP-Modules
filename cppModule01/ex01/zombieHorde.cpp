/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 04:01:56 by eduaserr          #+#    #+#             */
/*   Updated: 2025/08/11 00:42:21 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	createZombie(int N, std::string name){
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++){
		horde[i].setName(name);
	}
	return (horde);
}

Zombie* zombieHorde(int N, std::string name){
	Zombie	*Horde = createZombie(N, name);
	for (int i = 0; i < N; i++){
		Horde[i].announce();
	}
	return Horde;
}
