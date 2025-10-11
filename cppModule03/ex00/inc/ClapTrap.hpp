#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
	std::string _name;
	int			_hp;
	int			_ep;
	int			_ad;
public:
	ClapTrap();
	ClapTrap(const ClapTrap& data);
	ClapTrap(const std::string& name);
	~ClapTrap();

	void	setName(const std::string& name);
	void	setHp(const int hp);
	void	setEp(const int ep);
	void	setAd(const int ad);

	std::string	getName() const;
	int	getHp() const;
	int	getEp() const;
	int	getAd() const;
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	bool	isAlive();
};

#endif
