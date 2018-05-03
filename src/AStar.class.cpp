/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AStar.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:28:17 by trecomps          #+#    #+#             */
/*   Updated: 2018/05/03 12:47:55 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AStar.class.hpp"
#include "Node.class.hpp"

AStar::AStar(void)
{
	//std::cout << "Default constructor called" << std::endl;

	return ;
}

AStar::AStar(AStar const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

AStar::~AStar(void)
{
	//std::cout << "Destructor called" << std::endl;
	
	return ;
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
