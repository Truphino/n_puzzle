/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heuristics.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:03:00 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/03 12:04:06 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEURISTICS_CLASS_H
# define HEURISTICS_CLASS_H

#include <iostream>
#include <vector>
#include "NpuzzleSolver.class.hpp"
#include "Grid.class.hpp"

class Heuristics {

public :
	Heuristics(void);
	Heuristics(Grid const &grid);
	Heuristics(Heuristics const &rhs);
	virtual ~Heuristics(void);

	Heuristics	&operator=(Heuristics const &rhs);

	Grid const				&getGrid(void) const;
	void					setGrid(Grid const &grid);
	int						getSize(void) const;

	int						heuristic(Grid const &compare,
										std::string const &type) const;
	int						manhattanDistance(Grid const &cmp) const;
	int						linearConflict(Grid const &cmp) const;

private :
	unsigned int		inversions(Grid const &cmp, Axis axis, int tulpe) const;
	Grid				_hGrid;

};

std::ostream		&operator<<(std::ostream &o, Heuristics const &i);

#endif
