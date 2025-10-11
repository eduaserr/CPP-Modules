#include "inc/ClapTrap.hpp"

int main() {
	ClapTrap bot1;
	ClapTrap bot2("Clank");

	while (bot1.isAlive() && bot2.isAlive()){
		bot1.setAd(5);
		if (bot1.getEp() > 0)
		{
			bot1.attack(bot2.getName());
			bot2.takeDamage(bot1.getAd());
		}
		bot2.setAd(2);
		if (bot2.getEp() > 0)
		{
			bot2.attack(bot1.getName());
			bot1.takeDamage(bot2.getAd());
		}
	}
	return 0;
}
