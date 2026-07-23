/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:26:34 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/23 13:31:14 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename C, typename T>
void    sortCont(C& cont, unsigned int esize = 1)
{
	unsigned int pairs = cont.size() / (2*esize);
	// if can't split into pairs, return
	if (pairs < 1) // should be able to make a single pair to swap the elements
		return ;
    // split into pairs and swap elements
	std::vector<typename C::iterator> it;
	for (int i = 0; i < pairs; i++)
	{
		it[i] = cont.begin() + i * 2 * esize;
		if (it[i] > (it[i] + esize))
			swap(it[i], it[i] + esize, esize);
	}

	// call sortCont(cont, esize * 2)
	sortCont(cont, esize * 2);

	// Take out b's from main container to create pend
	
	// calculate Jacobstahl index to start with and binary insert pend elements into main (working backwards)

	// return
}