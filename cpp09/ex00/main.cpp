/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:30:02 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/07 16:15:24 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc file_name" << std::endl;
		return (1);
	}

	std::ifstream input(argv[1]);
	std::ifstream data("data.csv");

	if (!input.is_open() || !data.is_open())
		return ret_err("Error: could not open file.", 0);

	btcmap mdata;
	if (parse_data(data, mdata))
		parse_input(input, mdata);
	else
		return 1;
}