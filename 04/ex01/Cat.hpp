/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:35:06 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 19:55:12 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:

		Cat(void);
		~Cat();
		Cat(const Cat& original);

		Cat& operator=(const Cat& original);

		std::string		getIdeaInBrain(int index) const;

		void makeSound(void) const;
	
	private:

		Brain	*_brain;
};

#endif
