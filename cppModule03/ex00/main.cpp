#include "inc/ClapTrap.hpp"

static std::string	getWinner(ClapTrap& bot1, ClapTrap& bot2){
	std::string win = "Nobody";
	if (bot1.getHp() > bot2.getHp())
		win = bot1.getName();
	else if (bot1.getHp() < bot2.getHp())
		win = bot2.getName();
	return (win);
}

static void	botAttack(ClapTrap& attacker, ClapTrap& defender){
	if (attacker.getHp() > 0){
		attacker.attack(defender.getName());				//mensajes
		if (attacker.getEp() > 0){							// accion de atacar
			attacker.setEp(attacker.getEp() - 1);			// restar energia
			defender.takeDamage(attacker.getAd());			//recibir daño
		}
	}
	if (attacker.getItem())									//para diferenciar quien puede curarse
		attacker.beRepaired(3);								// reparar
}

int main() {
	ClapTrap bot1;
	ClapTrap bot2("Clank");

	//bot1.setAd(4);
	//bot2.setAd(2);
	//bot1.setEp(1);
	//bot2.setEp(3);
	//bot2.setItem(1);
	while (bot1.isAlive() && bot2.isAlive()){

		if (!bot1.getEp() && !bot2.getEp()){
			std::cout << "both bots are out of Energy Points. " << getWinner(bot1, bot2) << " wins!" << std::endl;
			break ;
		}

		botAttack(bot1, bot2);
		botAttack(bot2, bot1);

		std::cout << std::endl;
	}
	return 0;
}
