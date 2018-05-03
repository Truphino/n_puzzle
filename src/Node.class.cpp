/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:33:07 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/03 15:57:31 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.class.hpp"

Node::Node(void) : _grid(3), _parent(NULL)
{
	//std::cout << "Default constructor called" << std::endl;

	return ;
}

Node::Node(Grid const &grid) : _grid(grid), _parent(NULL)
{
	//std::cout << "Parametric constructor called" << std::endl;

	return ;
}

Node::Node(Grid const &grid, Node const *parent) : _grid(grid), _parent(parent)
{
	//std::cout << "Parametric constructor called" << std::endl;

	return ;
}

Node::Node(Node const &src) : _grid(3), _parent(NULL)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Node::~Node(void)
{
	//std::cout << "Destructor called" << std::endl;
	
	return ;
}

Grid		Node::getGrid(void) const
{
	return (this->_grid);
}

Node const	*Node::getParent(void) const
{
	return (this->_parent);
}

Node						*Node::newChild(Axis axis, int posNeg,
								std::vector<int> pos) const
{
	Grid		res(this->_grid.getSize(), this->_grid.getGrid());

	if (axis == COL)
	{
		res[pos[0]][pos[1]] = res[pos[0]][pos[1] + posNeg];
		res[pos[0]][pos[1] + posNeg] = 0;
	}
	else if (axis == ROW)
	{
		res[pos[0]][pos[1]] = res[pos[0] + posNeg][pos[1]];
		res[pos[0] + posNeg][pos[1]] = 0;
	}
	return (new Node(res, this));
}

std::list<Node*>			Node::nextNodes(void) const
{
	std::list<Node*>	res;
	std::vector<int>	pos;

	pos = this->getGrid().getPos(0);
	if (this->getGrid().isInGrid(pos[0] - 1))
		res.push_back(this->newChild(COL, -1, pos));
	if (this->getGrid().isInGrid(pos[0] + 1))
		res.push_back(this->newChild(COL, 1, pos));
	if (this->getGrid().isInGrid(pos[1] - 1))
		res.push_back(this->newChild(ROW, -1, pos));
	if (this->getGrid().isInGrid(pos[1] +1))
		res.push_back(this->newChild(ROW, 1, pos));
	return (res);
}

Node		&Node::operator=(Node const &rhs)
{
	//std::cout << "Assignement operator called" << std::endl;

	if (this != &rhs)
	{
		this->_grid = rhs.getGrid();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Node const &i)
{
	o << i.getGrid() << std::endl;

	return (o);
}
