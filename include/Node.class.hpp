/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:32:50 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/03 15:54:57 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_CLASS_H
# define NODE_CLASS_H

#include <iostream>
#include <list>
#include "Grid.class.hpp"

class Node {

public :

	Node(void);
	Node(Grid const &grid);
	Node(Grid const &grid, Node const *parent);
	Node(Node const &rhs);
	~Node(void);

	Node	&operator=(Node const &rhs);

	Grid					getGrid(void) const;
	Node const				*getParent(void) const;
	std::list<Node*>		nextNodes(void) const;
	Node					*newChild(Axis axis,
								int posNeg, std::vector<int> pos) const;

private :
	Grid			_grid;
	Node const		*_parent;

};

std::ostream		&operator<<(std::ostream &o, Node const &i);

#endif
