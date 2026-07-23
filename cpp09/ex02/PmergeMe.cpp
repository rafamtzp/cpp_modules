/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:26:34 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/23 18:00:34 by ramarti2         ###   ########.fr       */
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
	typename C::iterator first_end;
	typename C::iterator second_end;
	for (int i = 0; i < pairs; i++) // !!! Make sure not to worry about any leftover pairs!!!!!
	{
		it.push_back(cont.begin() + i * 2 * esize);
		first_end = it[i] + esize - 1;
		second_end = it[i] + 2*esize - 1;
		if (*first_end > *second_end)
			swap(it[i], it[i] + esize, esize);
		// I guess swap won't invalidate iterators if just rewrite without deleting
	}

	// call sortCont(cont, esize * 2)
	sortCont(cont, esize * 2);

	// Create pend and main out of iterators bi and ai
	std::vector<typename C::iterator> pend;
	std::vector<typename C::iterator> main;

	for (int i = 0; i < pairs; i++)
	{
		if (i > 0)
			pend.push_back(it[i]);
		else
			main.push_back(it[i]);
		main.push_back(it[i] + esize);
	}
	// LOOP: calculate Jacobstahl index

	// binary insert iterators from pend into main until no iterators are left

	// TODO figure out how to copy leftovers
	
	// return
}
