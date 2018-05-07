/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:32:50 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/07 13:01:48 by trecomps         ###   ########.fr       */
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

	Grid const				&getGrid(void) const;
	Node const				*getParent(void) const;
	std::list<Node*>		nextNodes(void) const;
	Node					*newChild(Axis axis,
								int posNeg, std::vector<int> pos) const;
	void					setG(int g);
	void					setH(int h);
	int						getF(void) const;
	int						getG(void) const;
	int						getH(void) const;

private :
	Grid			_grid;
	Node const		*_parent;

	int				_h;
	int				_g;

};

std::ostream				&operator<<(std::ostream &o, Node const &i);
std::list<Node*>::iterator	findGridList(std::list<Node*> *lst, Grid const &g);

#endif
