#include "inc/ClapTrap.hpp"

int main() {
	ClapTrap bot1;
	ClapTrap bot2("clank");

	bot1.attack("clank");
	bot2.takeDamage(10);
	return 0;
}
