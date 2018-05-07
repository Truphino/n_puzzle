/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:33:07 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/07 13:10:20 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.class.hpp"

Node::Node(void) : _grid(3), _parent(NULL), _h(-1), _g(-1)
{
	//std::cout << "Default constructor called" << std::endl;

	return ;
}

Node::Node(Grid const &grid) : _grid(grid), _parent(NULL), _h(-1), _g(-1)
{
	//std::cout << "Parametric constructor called" << std::endl;

	return ;
}

Node::Node(Grid const &grid, Node const *parent) :
						_grid(grid), _parent(parent), _h(-1), _g(-1)
{
	//std::cout << "Parametric constructor called" << std::endl;

	return ;
}

Node::Node(Node const &src) : _grid(3), _parent(NULL), _h(-1), _g(-1)
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

Grid const		&Node::getGrid(void) const
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

	if (axis == ROW)
	{
		res[pos[0]][pos[1]] = res[pos[0]][pos[1] + posNeg];
		res[pos[0]][pos[1] + posNeg] = 0;
	}
	else if (axis == COL)
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

void		Node::setG(int g)
{
	this->_g = g;
}

void		Node::setH(int h)
{
	this->_h = h;
}

int			Node::getG(void) const
{
	return (this->_g);
}

int			Node::getH(void) const
{
	return (this->_h);
}

int			Node::getF(void) const
{
	if (this->_g < 0 || this->_h < 0)
		return (-1);
	return (this->_g + this->_h);
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

std::list<Node*>::iterator			findGridList(std::list<Node*> *lst, Grid const &grid)
{
	std::list<Node*>::iterator	i;

	i = lst->begin();
	while (i != lst->end())
	{
		if ((*i)->getGrid() == grid)
		{
			return (i);
		}
		i++;
	}
	return (lst->end());
}
