/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:54:35 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/21 12:01:37 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cerrno>

int retErr(const char *msg)
{
    std::cerr << msg << std::endl;
    return 1;
}

int parseInput(char **argv)
{
    std::stringstream ss;
    std::string word;
    char *endptr;
    
    long    num;
    
    for (int i = 1; argv[i]; i++)
        ss << argv[i] << " ";

    int ct = 0;
    while (ss >> word)
    {
        num = std::strtol(word.c_str(), &endptr, 10);
        if (*endptr)
            return retErr("Error: invalid char.");
        if (errno == ERANGE || num < 0 || num > INT_MAX)
            return retErr("Error: integer out of range.");
        ct++;
    }
    std::cout << "The number of words is: " << ct << std::endl;
    return 0;
}

int main(int argc, char **argv)
{
    (void)argc;
    parseInput(argv);
    return 0;
}