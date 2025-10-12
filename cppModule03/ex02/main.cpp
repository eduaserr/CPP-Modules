#include "inc/ScavTrap.hpp"

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
	ScavTrap	Guard("Guardian");
	ClapTrap	bot("Tob");
	FragTrap	fbot;
	FragTrap	frag("Frank");

	//Scav.setAd(4);
	//Guard.setAd(2);
	//Scav.setEp(1);
	//Guard.setEp(3);
	//Guard.setItem(1);
	Guard.guardGate();
	std::cout << "\n ====FragTrap vs ScavTrap==== \n" << std::endl;
	while (frag.isAlive() && Guard.isAlive()){
		if (!frag.getEp() && !Guard.getEp()){
			std::cout << "both bots are out of Energy Points. " << getWinner(frag, Guard) << " wins!" << std::endl;
			break ;
		}

		botAttack(frag, Guard);
		botAttack(Guard, frag);

		std::cout << std::endl;
	}
	if (frag.getHp() > 0 && frag.getEp() > 0)
		frag.highFivesGuys();
	std::cout << "\n ====ScavTrap vs FragTrap==== \n" << std::endl;
	frag.revive(100, 10);
	while (bot.isAlive() && frag.isAlive()){

		if (!bot.getEp() && !frag.getEp()){
			std::cout << "both bots are out of Energy Points. " << getWinner(bot, frag) << " wins!" << std::endl;
			break ;
		}

		botAttack(bot, frag);
		botAttack(frag, bot);

		std::cout << std::endl;
	}
	if (frag.getHp() > 0 && frag.getEp() > 0)
		frag.highFivesGuys();
	std::cout << "\n ====FragTrap vs FragTrap==== \n" << std::endl;
	frag.revive(100, 10);
	while (fbot.isAlive() && frag.isAlive()){

		if (!fbot.getEp() && !frag.getEp()){
			std::cout << "both bots are out of Energy Points. " << getWinner(fbot, frag) << " wins!" << std::endl;
			break ;
		}

		botAttack(fbot, frag);
		botAttack(frag, fbot);

		std::cout << std::endl;
	}
	if (frag.getHp() > 0 && frag.getEp() > 0)
		frag.highFivesGuys();
	else if (fbot.getHp() > 0  && fbot.getEp() > 0)
		fbot.highFivesGuys();

	return 0;
}
