/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:30:02 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/02 16:36:30 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>

int	ret_err(const char *msg)
{
	std::cerr << msg << std::endl;
	return 1;
}

std::map<std::string, float>	parse_input(std::ifstream& input)
{
	std::map<std::string, float>	minput;

	
}

void	print_bitcoin(std::ifstream& input, std::ifstream& data)
{
	
}

bool	grater_than_prev_date(std::string date, std::string prev)
{
	int pos = 0;
	int incr = 4;

	int quantity1;
	int quantity2;

	while (pos < 10)
	{
		quantity1 = std::atoi(prev.substr(pos, incr).c_str());
		quantity2 = std::atoi(date.substr(pos, incr).c_str());
		
		if (quantity2 < quantity1)
			return false;
		if (quantity2 > quantity1)
			return true;
		
		pos += (incr + 1);
		incr = 2;
	}
	return false;
}

bool	is_valid_date(std::string date)
{
	
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc file_name" << std::endl;
		return 1;
	}
	
	std::ifstream input(argv[1]);
	std::ifstream data("data.csv");
	
	if (!input.is_open() || !data.is_open())
		return ret_err("Error: could not open file.");

	std::map<std::string, float> map_input = parse_input(input);
	print_bitcoin(input, data);
}