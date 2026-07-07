/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:30:02 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/07 14:26:09 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <fstream>
#include <iostream>
#include <map>

typedef std::map<std::string, double> btcmap;

int	ret_err(const char *msg)
{
	std::cerr << msg << std::endl;
	return (1);
}

bool	aredigits(std::string date, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		if (!std::isdigit(date.at(i)))
			return (false);
	}
	return (true);
}

bool	is_valid_date(std::string date, btcmap &mdata, bool isinput)
{
	int	year;
	int	month;
	int	day;

	if (!aredigits(date, 0, 4) || !aredigits(date, 5, 7) || !aredigits(date, 8, 10) 
	    || date.at(4) != '-' || date.at(7) != '-')
		return (false);
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2022)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	// if storing database in map and there's a stored date that is >= this date, not valid.
	if (!isinput && !mdata.empty() && mdata.lower_bound(date) != mdata.end())
		return (false);
	return (true);
}

bool	is_valid_value(std::string value, bool isinput)
{
	double	conversion;
	char	*endptr;

	errno = 0;
	if (!isdigit(value.at(0)))
		return (false);
	conversion = std::strtod(value.c_str(), &endptr);
	if (errno == ERANGE || (*endptr != '\0' && *endptr != '\n'))
		return (false);
	if (isinput && (conversion < 0 || conversion > 1000))
		return (false);
	return (true);
}

void	print_result(btcmap &mdata, std::string date,
		std::string value)
{
	double	result;
	char	*endptr;

	btcmap::iterator it = mdata.lower_bound(date);
	if (it->first == date)
		result = std::strtod(value.c_str(), &endptr) * it->second; // data stored as double
	else
		result = std::strtod(value.c_str(), &endptr) * (--it)->second;
	if (*endptr)
	{
		ret_err("Error: print_result");
		return ;
	}
	std::cout << date << " => " << value << " = " << result << std::endl;
}

bool	parse_input(std::ifstream &input, btcmap &mdata)
{
	int	datelen;

	std::string line;
	std::string date;
	std::string value;
	std::getline(input, line);
	if (line != "date | value\n")
	{
		ret_err("Error: bad header."); // Should I return here??
		return (false);
	}
	while (std::getline(input, line))
	{
		datelen = line.find(" | ");
		if (datelen == 10 && line.length() > 13)
		{
			date = line.substr(0, datelen);
			value = line.substr(datelen + 3, line.length() - 13);
		}
		else
		{
			ret_err("Error: bad input.");
			continue ;
		}
		if (!is_valid_date(date, mdata, true))
			ret_err("Error: invalid date.");
		else if (!is_valid_value(value, true))
			ret_err("Error: invalid value.");
		else
			print_result(mdata, date, value);
	}
}

bool	parse_data(std::ifstream &data, btcmap &mdata)
{
	int	datelen;

	std::string line;
	std::string date;
	std::string value;

	std::getline(data, line);
	if (line != "date,exchange_rate\n")
	{
		ret_err("Error: bad header in data."); // Should I return here?????
		return (false);
	}
	while (std::getline(data, line))
	{
		datelen = line.find(",");
		if (datelen == 10 && line.length() > 11)
		{
			date = line.substr(0, datelen);
			value = line.substr(datelen + 1, line.length() - 11);
		}
		else
		{
			ret_err("Error: bad input in data.");
			continue ;
		}
		if (!is_valid_date(date, mdata, false))
			ret_err("Error: invalid date in data.");
		else if (!is_valid_value(value, false))
			ret_err("Error: invalid value in data.");
		else
			mdata.insert({date, std::strtod(value.c_str(), NULL)});
	}
}

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
		return ret_err("Error: could not open file.");

	btcmap mdata;
	parse_data(data, mdata);
	parse_input(input, mdata);
}