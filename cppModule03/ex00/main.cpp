#include "inc/ClapTrap.hpp"

int main() {
	ClapTrap bot1;
	ClapTrap bot2("Clank");

	bot1.setAd(1);
	bot2.setAd(2);
	bot1.setEp(1);
	bot2.setEp(3);
	while (bot1.isAlive() && bot2.isAlive()){

		// tie case / getWinner
		if (!bot1.getEp() && !bot2.getEp()){
			std::string win = "Nobody";
			if (bot1.getHp() > bot2.getHp())
				win = bot1.getName();
			else if (bot1.getHp() < bot2.getHp())
				win = bot2.getName();
			std::cout << "both bots are out of Energy Points. " << win << " wins!" << std::endl;
			break ;
		}

		// bot 1 attack
		if (bot1.getHp() > 0)
		{
			bot1.attack(bot2.getName());
			if (bot1.getEp() > 0){
				bot1.setEp(bot1.getEp() - 1);
				bot2.takeDamage(bot1.getAd());

			}
		}
		// bot 2 attack
		if (bot2.getHp() > 0)
		{
			bot2.attack(bot1.getName());		//mensajes
			if (bot2.getEp() > 0){				// accion de atacar
				bot2.setEp(bot2.getEp() - 1);	// restar energia
				bot1.takeDamage(bot2.getAd());	//recibir daño 
			}
			bot2.beRepaired(3);					// reparar
		}
		std::cout << std::endl;
	}
	return 0;
}
