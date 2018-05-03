/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NpuzzleSolver.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:46:45 by trecomps          #+#    #+#             */
/*   Updated: 2018/04/27 14:49:04 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLESOLVER_CLASS_H
# define NPUZZLESOLVER_CLASS_H

#include <iostream>
#include <vector>
#include "Grid.class.hpp"

class NpuzzleSolver {

public :

	NpuzzleSolver(void);
	NpuzzleSolver(int const n);
	NpuzzleSolver(NpuzzleSolver const &rhs);
	~NpuzzleSolver(void);

	Grid const		&getGrid(void) const;

	void			solveGrid(void);

private :
	NpuzzleSolver	&operator=(NpuzzleSolver const &rhs);
	void			firstRow(int *x, int *y, int *x_max, int *y_max, int *v);
	void			lastRow(int *x, int *y, int *x_max, int *y_max, int *v);
	void			firstColumn(int *x, int *y, int *x_max, int *y_max, int *v);
	void			lastColumn(int *x, int *y, int *x_max, int *y_max, int *v);

	Grid			_grid;

};

std::ostream		&operator<<(std::ostream &o, NpuzzleSolver const &i);

#endif
