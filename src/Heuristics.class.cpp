/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heuristics.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:03:07 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/03 12:04:28 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Heuristics.class.hpp"

Heuristics::Heuristics(void) : _hGrid(3)
{
	return ;
}

Heuristics::Heuristics(Grid const &grid)
								: _hGrid(grid)
{
	//std::cout << "Parametric constructor called" << std::endl;

	return ;
}

Heuristics::Heuristics(Heuristics const &src) : _hGrid(src.getGrid())
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Heuristics::~Heuristics(void)
{
	//std::cout << "Destructor called" << std::endl;
	
	return ;
}

Grid const		&Heuristics::getGrid(void) const
{
	return (this->_hGrid);
}

void			Heuristics::setGrid(Grid const &grid)
{
	this->_hGrid = grid;
}

int				Heuristics::getSize(void) const
{
	return (this->_hGrid.getSize());
}

int				Heuristics::manhattanDistance(Grid const &cmp) const
{
	int						i = 0;
	int						f = 0;
	std::vector<int>		finalPos(2, -1);
	std::vector<int>		tmpPos(2, -1);

	while (++i < cmp.getSize() * cmp.getSize())
	{
		finalPos = this->getGrid().getPos(i);
		tmpPos = cmp.getPos(i);
		f += abs(finalPos[0] - tmpPos[0]);
		f += abs(finalPos[1] - tmpPos[1]);
	}
	return (f);
}

unsigned int			Heuristics::inversions(Grid const &cmp,
													Axis axis,
													int tulpe) const
{
	std::vector<int>	finalPos;
	std::vector<int>	tmpPos;
	int					inversions = 0;
	int					i = 0;
	int					j = 0;

	finalPos = this->getGrid().getTulpe(axis, tulpe);
	tmpPos = cmp.getTulpe(axis, tulpe);
	while (++i < this->getSize())
	{
		if (tmpPos[i] != 0 &&
			std::find(finalPos.begin(), finalPos.end(), tmpPos[i])
				!= finalPos.end())
		{
			j = -1;
			while (++j < i)
				if (tmpPos[j] != 0 &&
					std::find(finalPos.begin(), finalPos.end(), tmpPos[j])
						!= finalPos.end())
					if ((tmpPos[i] < tmpPos[j]) != (finalPos[i] < finalPos[j]))
						inversions++;
		}
	}
	return (inversions);
}

int				Heuristics::linearConflict(Grid const &cmp) const
{
	unsigned int		conflicts = 0;
	int					i = 0;

	while (i < this->getSize())
	{
		conflicts += this->inversions(cmp, ROW, i);
		conflicts += this->inversions(cmp, COL, i);
		i++;
	}
	return (2 * conflicts + this->manhattanDistance(cmp));
}

int				Heuristics::heuristic(Grid const &cmp,
										std::string const &type) const
{
	if (type == "manhattanDistance")
		return (this->manhattanDistance(cmp));
	else if (type == "linearConflict")
		return (this->linearConflict(cmp));
	return (-1);
}

Heuristics		&Heuristics::operator=(Heuristics const &rhs)
{
	//std::cout << "Assignement operator called" << std::endl;

	if (this != &rhs)
	{
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Heuristics const &i)
{
	o << i.getGrid();

	return (o);
}
