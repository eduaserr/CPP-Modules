#ifndef SCAVPTRAP_HPP
#define SCAVPTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
	ScavTrap();
	ScavTrap(const ScavTrap& data);
	ScavTrap(const std::string& name);
	ScavTrap& operator=(const ScavTrap& bot);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();
};

#endif