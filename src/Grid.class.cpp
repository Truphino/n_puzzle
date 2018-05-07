/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:37:35 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/07 11:00:27 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grid.class.hpp"
#include <exception>

Grid::Grid(int size) : _size(size),
						_grid(_size, std::vector<int>(_size))
{
	//std::cout << "Parametric constructor called" << std::endl;

	return ;
}

Grid::Grid(int size, std::vector< std::vector<int> > const &grid) : _size(size),
						_grid(grid)
{
	//std::cout << "Parametric constructor called" << std::endl;

	return ;
}

Grid::Grid(Grid const &src) : _size(src.getSize())
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Grid::~Grid(void)
{
	//std::cout << "Destructor called" << std::endl;
	
	return ;
}

int			Grid::getSize(void) const
{
	return (this->_size);
}

std::vector< std::vector<int> > const		&Grid::getGrid(void) const
{
	return (this->_grid);
}

std::vector<int> const	&Grid::operator[](int idx) const
{
	return (this->_grid[idx]);
}

std::vector<int>	&Grid::operator[](int idx)
{
	return (this->_grid[idx]);
}

Grid		&Grid::operator=(Grid const &rhs)
{
	//std::cout << "Assignement operator called" << std::endl;

	if (this != &rhs)
	{
		this->_size = rhs.getSize();
		this->_grid = rhs.getGrid();
	}
	return (*this);
}

std::vector<int>	Grid::getRow(int row) const
{
	int					i = -1;
	std::vector<int>	res(this->_size, 0);

	if (row < 0 || row >= this->_size)
		throw std::out_of_range("Row not in puzzle");
	while (++i < this->_size)
		res[i] = this->_grid[row][i];
	return (res);
}

std::vector<int>	Grid::getColumn(int column) const
{
	int					i = -1;
	std::vector<int>	res(this->_size, 0);

	if (column < 0 || column >= this->_size)
		throw std::out_of_range("Column not in puzzle");
	while (++i < this->_size)
		res[i] = this->_grid[i][column];
	return (res);
}

std::vector<int>	Grid::getTulpe(Axis axis, int i) const
{
	if (axis == ROW)
		return (this->getRow(i));
	else if (axis == COL)
		return (this->getColumn(i));
	throw std::out_of_range("Bad Axis");
}

std::vector<int>	Grid::getPos(int i) const
{
	std::vector<int>	pos(2, -1);

	if (i < 0 || i >= this->getSize() * this->getSize())
		throw std::out_of_range("Int not in puzzle");
	pos[0] = 0;
	while (pos[0] != this->getSize())
	{
		pos[1] = 0;
		while (pos[1] != this->getSize())
		{
			if (this->getGrid()[pos[0]][pos[1]] == i)
				return (pos);
			pos[1] += 1;
		}
		pos[0] += 1;
	}
	throw std::out_of_range("Int not in puzzle");
}

int				Grid::isInGrid(int s) const
{
	if (s >= 0 && s < this->_size)
		return (1);
	return (0);
}

bool			operator==(Grid const &a, Grid const &b)
{
	int			size;

	if (a.getSize() != b.getSize())
		return (0);
	else
	{
		size = a.getSize();
		if (a.getGrid() == b.getGrid())
			return (1);
	}
	return (0);
}

std::ostream	&operator<<(std::ostream &o, Grid const &ptr)
{
	int			i;
	int			j;
	std::vector< std::vector<int> >		grid;

	i = 0;
	grid = ptr.getGrid();
	while (i < ptr.getSize())
	{
		j = 0;
		while (j < ptr.getSize())
		{
			o << grid[i][j] << "\t ";
			j++;
		}
		o << std::endl;
		o << std::endl;
		o << std::endl;
		i++;
	}

	return (o);
}
