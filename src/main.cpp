/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:35:49 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/07 13:16:10 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NpuzzleSolver.class.hpp"
#include "Heuristics.class.hpp"
#include "Node.class.hpp"
#include "AStar.class.hpp"

void	print_path(Node const *end)
{
	if (end == NULL)
		return;
	print_path(end->getParent());
	std::cout << *end << std::endl;
}

int		main(void)
{
	NpuzzleSolver					n(3);
	std::vector< std::vector<int> >	t(3, std::vector<int>(3));
	std::vector<int>				row;
	Heuristics						h;

	t[0][0] = 2;
	t[0][1] = 3;
	t[0][2] = 0;
	t[1][0] = 1;
	t[1][1] = 4;
	t[1][2] = 5;
	t[2][0] = 8;
	t[2][1] = 7;
	t[2][2] = 6;
	Grid							grid(3, t);
	n.solveGrid();
	h.setGrid(n.getGrid());
	AStar							a_star(n.getGrid(), "linearConflict");
	Node							node(grid);
	Node							*res;
	std::cout << node << std::endl;
	res = a_star.a_star(&node);
	if (res)
		print_path(res);
	else
		std::cout << "No path" << std::endl;
}
