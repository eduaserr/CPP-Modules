#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap{
	public:
	FragTrap();
	FragTrap(const FragTrap& data);
	FragTrap(const std::string& name);
	FragTrap& operator=(const FragTrap& bot);
	~FragTrap();

	void	attack(const std::string& target);
	void	highFivesGuys(void);

};

#endif