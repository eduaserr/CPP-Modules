#include "inc/ScavTrap.hpp"

static std::string	getWinner(ClapTrap& bot1, ClapTrap& bot2){
	std::string win = "Nobody";
	if (bot1.getHp() > bot2.getHp())
		win = bot1.getName();
	else if (bot1.getHp() < bot2.getHp())
		win = bot2.getName();
	return (win);
}

static void	ScavTrapAttack(ScavTrap& attacker, ScavTrap& defender){
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
	ScavTrap	Scrav;
	ScavTrap	Guard("Guardian");

	//Scrav.setAd(4);
	//Guard.setAd(2);
	//Scrav.setEp(1);
	//Guard.setEp(3);
	//Guard.setItem(1);
	Scrav.guardGate();
	Guard.guardGate();
	while (Scrav.isAlive() && Guard.isAlive()){

		if (!Scrav.getEp() && !Guard.getEp()){
			std::cout << "both bots are out of Energy Points. " << getWinner(Scrav, Guard) << " wins!" << std::endl;
			break ;
		}

		ScavTrapAttack(Scrav, Guard);
		ScavTrapAttack(Guard, Scrav);

		std::cout << std::endl;
	}
	return 0;
}
