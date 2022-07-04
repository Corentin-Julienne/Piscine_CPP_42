/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:21 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 20:22:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) :_name(name)
{
	this->_weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon& weapon) : _name(name) 
{
	this->_weapon = &weapon;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his ";
	std::cout << this->_weapon->getType() << std::endl;
}
