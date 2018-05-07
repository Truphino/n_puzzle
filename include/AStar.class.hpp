/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AStar.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:28:25 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/07 11:16:51 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTAR_CLASS_H
# define ASTAR_CLASS_H

#include <iostream>
#include "Node.class.hpp"
#include "Grid.class.hpp"
#include "Heuristics.class.hpp"

class AStar {

public :

	AStar(Grid const &goal, std::string const &heurType);
	~AStar(void);

	Node		*a_star(Node *start);
	void		loopOnChilds(Node *parent);

private :
	AStar(void);
	AStar(AStar const &rhs);
	AStar	&operator=(AStar const &rhs);

	std::list<Node*>::iterator		getMinFNode();

	std::list<Node*>	_open_list;
	std::list<Node*>	_closed_list;
	Grid const			&_goal;
	Heuristics			_heur;
	std::string const	&_heurType;

};

std::ostream		&operator<<(std::ostream &o, AStar const &i);

#endif
