#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("noName"), _hp(10), _ep(10), _ad(0), _item(0){
	std::cout << "Constructor bot " << _name << " called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& bot): _name(bot._name),  _hp(bot._hp),  _ep(bot._ep), _ad(bot._ad), _item(bot._item){
	std::cout << "Copy constructor called for " << _name << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& bot)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &bot)
	{
		_name = bot._name;
		_hp = bot._hp;
		_ep = bot._ep;
		_ad = bot._ad;
	}
	return (*this);
}
ClapTrap::ClapTrap(const std::string& name): _name(name), _hp(10), _ep(10), _ad(0), _item(0){
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
		if ((_hp - (int)amount) < 0)
			amount = _hp;
		setHp(getHp() - amount);
	}
	if (_hp < 1)
		std::cout << _name << " fainted" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_ep)
		std::cout << _name << " can't repair, no energy left!" << std::endl;
	else if (this->_hp + amount > 10)
		amount = 10 - _hp;
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
void	ClapTrap::setItem(int item){
	this->_item = item;
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
int	ClapTrap::getItem() const {
	return (this->_item);
}

bool	ClapTrap::isAlive() const {
	std::cout << _name << ": hp left " << _hp << std::endl;
	if (this->_hp < 1)
		std::cout << _name << " has no more health points left!" << std::endl;
	return (this->_hp > 0 ? true : false);
}