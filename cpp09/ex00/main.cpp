/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:30:02 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/02 17:14:37 by ramarti2         ###   ########.fr       */
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

bool	parse_input(std::ifstream& input, std::map<std::string, float>& minput)
{
	std::string line;

	while (std::getline(input, line))
	{
		if (line.find('|') == std::string::npos)
			return false;
		if ()
	}

	
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
	std::map<std::string, float> map_data = parse_data(data);
	print_bitcoin(input, data);
}