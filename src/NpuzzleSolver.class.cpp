/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NpuzzleSolver.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:46:09 by trecomps          #+#    #+#             */
/*   Updated: 2018/04/27 14:49:01 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NpuzzleSolver.class.hpp"
#include <vector>

NpuzzleSolver::NpuzzleSolver(void) :
							_grid(3)
{
	//std::cout << "Default constructor called" << std::endl;

	return ;
}

NpuzzleSolver::NpuzzleSolver(int const size) :
							_grid(size)
{
	//std::cout << "Parametric constructor called" << std::endl;

	return ;
}

NpuzzleSolver::NpuzzleSolver(NpuzzleSolver const &src) : _grid(src.getGrid().getSize())
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

NpuzzleSolver::~NpuzzleSolver(void)
{
	//std::cout << "Destructor called" << std::endl;
	
	return ;

}
NpuzzleSolver		&NpuzzleSolver::operator=(NpuzzleSolver const &rhs)
{
	//std::cout << "Assignement operator called" << std::endl;

	if (this != &rhs)
	{
	}
	return (*this);
}

Grid const				&NpuzzleSolver::getGrid() const
{
	return(this->_grid);
}

void		NpuzzleSolver::firstRow(
							int *x, int *y, int *x_max, int *y_max, int *v)
{
	int		i;

	static_cast<void>(x_max);
	i = *y - 1;
	while (++i < *y_max && ++(*v))
	{
		if (*v == this->_grid.getSize() * this->_grid.getSize())
			*v = 0;
		this->_grid[*x][i] = *v;
	}
	(*x)++;
}

void		NpuzzleSolver::lastColumn(
							int *x, int *y, int *x_max, int *y_max, int *v)
{
	int		i;

	static_cast<void>(y);
	i = *x - 1;
	while (++i < *x_max && ++*v)
	{
		if (*v == this->_grid.getSize() * this->_grid.getSize())
			*v = 0;
		this->_grid[i][*y_max - 1] = *v;
	}
	(*y_max)--;
}

void		NpuzzleSolver::lastRow(
							int *x, int *y, int *x_max, int *y_max, int *v)
{
	int		i;

	if (*x < *x_max)
	{
		i = *y_max;
		while (--i >= *y && ++*v)
		{
			if (*v == this->_grid.getSize() * this->_grid.getSize())
				*v = 0;
			this->_grid[*x_max - 1][i] = *v;
		}
		(*x_max)--;
	}
}

void		NpuzzleSolver::firstColumn(
							int *x, int *y, int *x_max, int *y_max, int *v)
{
	int		i;

	if (*y < *y_max)
	{
		i = *x_max;
		while (--i >= *x && ++*v)
		{
			if (*v == this->_grid.getSize() * this->_grid.getSize())
				*v = 0;
			this->_grid[i][*y] = *v;
		}
		(*y)++;
	}
}

void		NpuzzleSolver::solveGrid(void)
{
	int		x = 0;
	int		y = 0;
	int		x_max = this->_grid.getSize();
	int		y_max = this->_grid.getSize();
	int		v = 0;

	while (x < x_max && y < y_max)
	{
		this->firstRow(&x, &y, &x_max, &y_max, &v);
		this->lastColumn(&x, &y, &x_max, &y_max, &v);
		this->lastRow(&x, &y, &x_max, &y_max, &v);
		this->firstColumn(&x, &y, &x_max, &y_max, &v);
	}
}

std::ostream	&operator<<(std::ostream &o, NpuzzleSolver const &ptr)
{
	o << ptr.getGrid() << std::endl;

	return (o);
}
