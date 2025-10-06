#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("noName"), _hp(10), _ep(10), _ad(0){
    std::cout << "Constructor bot " << _name << " called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& data){(void)data;}

ClapTrap::ClapTrap(const std::string& name): _hp(10), _ep(10), _ad(0){
    this->_name = name;
    std::cout << "Constructor bot " << _name << " called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& data){(void)data;
    return (*this);}
ClapTrap::~ClapTrap(){
    std::cout << "Destructor bot " << _name << " called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
    std::cout << "Claptrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
    (void)amount;
    this->_hp = _hp - amount;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
    (void)amount;
    this->_hp = _hp + amount;
}