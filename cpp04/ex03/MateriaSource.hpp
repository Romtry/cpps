/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:27:10 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/02 12:33:29 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
						MateriaSource();
						MateriaSource(MateriaSource &original);
						~MateriaSource();
		MateriaSource	&operator=(MateriaSource &original);
		void			learnMateria(AMateria *m);
		AMateria		*createMateria(const std::string &type);

	protected:
		
	private:
		AMateria	*_learned[4];
};
