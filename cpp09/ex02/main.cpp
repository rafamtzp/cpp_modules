/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:54:35 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/21 13:00:29 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <vector>
#include <deque>

int retErr(const char *msg)
{
    std::cerr << msg << std::endl;
    return 1;
}
template <typename C>
int parseInput(char **argv, C& cont)
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
        cont.push_back(static_cast<int>(num));
        ct++;
    }
    std::cout << "The number of words is: " << ct << std::endl;
    return 0;
}

template <typename C>
void    printCont(const C& cont)
{
    typename C::const_iterator end = cont.end();

    std::cout << "Container values: ";
    for (typename C::const_iterator it = cont.begin(); it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char **argv)
{
    std::deque<int>  maind;
    std::vector<int> mainv;
    (void)argc;
    if (parseInput(argv, maind) == 1 || parseInput(argv, mainv))
        return 1;
    printCont(maind);
    printCont(mainv);
    return 0;
}