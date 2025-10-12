#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap Constructor bot " << _name << " called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& bot) : ClapTrap(bot) {
	std::cout << "ScavTrap Copy constructor called for " << _name << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name){
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap Constructor bot " << _name << " called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}
ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor bot " << _name << " called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_ep)
		std::cout << _name << " can't attack " << target << ", no energy left!" << std::endl;
	else if (this->_ep > 0 && this->_hp > 0)
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}