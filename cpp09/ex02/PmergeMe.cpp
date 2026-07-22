/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:26:34 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/22 16:21:07 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename C, typename T>
void    sortCont(C& cont, unsigned int pairsize = 1)
{
	// if can't split into pairs, return
	if (cont.size() / pairsize <= 1)
		return ;
    // split into pairs and swap them
	C pairs
	
	// call sortCont(cont, pairsize * 2)
	sortCont(cont, pairsize * 2);

	// Take out b's from main container to create pend

	// calculate Jacobstahl index to start with and binary insert pend elements into main (working backwards)

	// return
}