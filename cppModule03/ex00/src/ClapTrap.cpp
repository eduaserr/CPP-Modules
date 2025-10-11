#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("noName"), _hp(10), _ep(10), _ad(0){
	std::cout << "Constructor bot " << _name << " called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& data){
	*this = data;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hp(10), _ep(10), _ad(0){
	std::cout << "Constructor bot " << _name << " called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor bot " << _name << " called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_ep)
		std::cout << _name << " can't attack " << target << ", no energy left!" << std::endl;
	else if (this->_ep > 0 && this->_hp > 0){
		std::cout << "Claptrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0){
		std::cout << "Claptrap " << _name << " received -" << amount << " points of damage" << std::endl;
		setHp(getHp() - amount);
	}
	if (_hp < 1)
		std::cout << _name << " fainted" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_ep)
		std::cout << _name << " can't repair, no energy left!" << std::endl;
	if (this->_ep > 0 && this->_hp > 0){
		std::cout << "Claptrap " << _name << " repaired +" << amount << " health points" << std::endl;
		setHp(getHp() + amount);
		_ep--;
	}
}

void	ClapTrap::setName(const std::string& name){
	this->_name = name;
}
void	ClapTrap::setHp(int hp){
	this->_hp = hp;
}
void	ClapTrap::setAd(int ad){
	this->_ad = ad;
}
void	ClapTrap::setEp(int ep){
	this->_ep = ep;
}

std::string	ClapTrap::getName() const {
	return (this->_name);
}
int	ClapTrap::getHp() const {
	return (this->_hp);
}
int	ClapTrap::getAd() const {
	return (this->_ad);
}
int	ClapTrap::getEp() const {
	return (this->_ep);
}

bool	ClapTrap::isAlive() {
	std::cout << _name << ": hp left " << _hp << std::endl;
	if (this->_hp < 1)
		std::cout << _name << " has no more health points left!" << std::endl;
	return (this->_hp > 0 ? true : false);
}