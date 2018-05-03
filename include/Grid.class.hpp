/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:37:15 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/03 15:13:30 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_CLASS_H
# define GRID_CLASS_H

#include <iostream>
#include <vector>

enum Axis {ROW, COL};

class Grid {

public :

	Grid(int size);
	Grid(int size, std::vector< std::vector<int> > const &grid);
	Grid(Grid const &rhs);
	~Grid(void);

	Grid					&operator=(Grid const &rhs);
	std::vector<int>		&operator[](int idx);
	std::vector<int> const	&operator[](int idx) const;

	int										getSize(void) const;
	std::vector< std::vector<int> > const	&getGrid(void) const;
	std::vector<int>						getPos(int) const;
	std::vector<int>						getRow(int) const;
	std::vector<int>						getColumn(int) const;
	std::vector<int>						getTulpe(Axis, int) const;
	int										isInGrid(int s) const;

private :
	int									_size;
	std::vector< std::vector<int> >		_grid;

};

std::ostream		&operator<<(std::ostream &o, Grid const &i);

#endif
