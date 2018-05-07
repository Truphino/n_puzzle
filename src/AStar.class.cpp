/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AStar.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:28:17 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/07 13:03:18 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AStar.class.hpp"
#include "Node.class.hpp"

AStar::AStar(Grid const &goal, std::string const &heurType) :
				_goal(goal), _heur(goal), _heurType(heurType)
{
	//std::cout << "Default constructor called" << std::endl;

	return ;
}

AStar::~AStar(void)
{
	//std::cout << "Destructor called" << std::endl;
	
	return ;
}

void		AStar::loopOnChilds(Node *parent)
{
	std::list<Node*>			childs;
	std::list<Node*>::iterator	i;
	std::list<Node*>::iterator	actual_node;

	childs = parent->nextNodes();
	i = childs.begin();
	while (i != childs.end())
	{
		(*i)->setG(parent->getG() + 1);
		(*i)->setH(this->_heur.heuristic((*i)->getGrid(), this->_heurType));
		if (findGridList(&(this->_closed_list), (*i)->getGrid())
				== this->_closed_list.end())
		{
			if ((actual_node =
					findGridList(&(this->_open_list), (*i)->getGrid()))
					== this->_open_list.end())
			{
				this->_open_list.push_back(*i);
			}
			else
			{
				if ((*i)->getG() < (*actual_node)->getG())
				{
					this->_open_list.erase(actual_node);
					this->_open_list.push_back(*i);
				}
			}
		}
		i++;
	}
}

Node		*AStar::a_star(Node *start)
{
	std::list<Node*>::iterator	process;

	start->setG(0);
	start->setH(this->_heur.heuristic(start->getGrid(), this->_heurType));
	this->_open_list.push_back(start);

	while (!this->_open_list.empty())
	{
		process = this->getMinFNode();
		if ((*process)->getGrid() == this->_goal)
			return (*process);
		this->_closed_list.push_back(*process);
		this->_open_list.erase(process);
		this->loopOnChilds(*process);
	}

	return (NULL);
}

std::list<Node*>::iterator		AStar::getMinFNode(void)
{
	std::list<Node*>::iterator	i;
	std::list<Node*>::iterator	min_f;
	int							f;

	i = this->_open_list.begin();
	min_f = i;
	while (i != this->_open_list.end())
	{
		f = (*i)->getF();
		if (f > 0 && f < (*min_f)->getF())
			min_f = i;
		i++;
	}
	return (min_f);
}

AStar		&AStar::operator=(AStar const &rhs)
{
	//std::cout << "Assignement operator called" << std::endl;

	if (this != &rhs)
	{
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, AStar const &i)
{
	static_cast<void>(i);
	return (o);
}
