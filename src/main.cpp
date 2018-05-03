/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:35:49 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/03 16:13:07 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NpuzzleSolver.class.hpp"
#include "Heuristics.class.hpp"
#include "Node.class.hpp"

int		main(void)
{
	NpuzzleSolver					n(3);
	std::vector< std::vector<int> >	t(3, std::vector<int>(3));
	std::vector<int>				row;
	Heuristics						h;

	t[0][0] = 7;
	t[0][1] = 6;
	t[0][2] = 3;
	t[1][0] = 4;
	t[1][1] = 5;
	t[1][2] = 8;
	t[2][0] = 1;
	t[2][1] = 2;
	t[2][2] = 0;
	Grid							grid(3, t);
	n.solveGrid();
	h.setGrid(n.getGrid());

	Node							node(grid);
	std::list<Node*>				childs = node.nextNodes();
	std::cout << h << std::endl;
	std::cout << node << std::endl;
	for (std::list<Node*>::iterator i = childs.begin(); i != childs.end(); i++)
		std::cout << **i << std::endl;
	std::cout << h.heuristic(grid, "manhattanDistance") << std::endl;
	std::cout << h.heuristic(grid, "linearConflict") << std::endl;
}
