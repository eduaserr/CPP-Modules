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
	int			_item;
public:
	ClapTrap();
	ClapTrap(const ClapTrap& data);
	ClapTrap(const std::string& name);
	ClapTrap& operator=(const ClapTrap& bot);
	~ClapTrap();

	void	setName(const std::string& name);
	void	setHp(int hp);
	void	setEp(int ep);
	void	setAd(int ad);
	void	setItem(int item);

	std::string	getName() const;
	int	getHp() const;
	int	getEp() const;
	int	getAd() const;
	int	getItem() const;
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	bool	isAlive() const;
};

#endif
