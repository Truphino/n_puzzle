/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AStar.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:28:25 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/03 12:47:52 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTAR_CLASS_H
# define ASTAR_CLASS_H

#include <iostream>

class AStar {

public :

	AStar(void);
	AStar(AStar const &rhs);
	~AStar(void);

	AStar	&operator=(AStar const &rhs);

private :

};

std::ostream		&operator<<(std::ostream &o, AStar const &i);

#endif
