#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap Constructor bot " << _name << " called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& bot) : ClapTrap(bot) {
	std::cout << "FragTrap Copy constructor called for " << _name << std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name){
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap Constructor bot " << _name << " called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}
FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor bot " << _name << " called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (!this->_ep)
		std::cout << _name << " can't attack " << target << ", no energy left!" << std::endl;
	else if (this->_ep > 0 && this->_hp > 0)
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << _name << ": Mission completed, High Five!" << std::endl;
}
