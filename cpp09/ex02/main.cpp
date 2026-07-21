/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:54:35 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/21 15:44:24 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <vector>
#include <deque>
#include <sys/time.h>

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
    return 0;
}

template <typename C>
void    printCont(const C& cont, bool before)
{
    typename C::const_iterator end = cont.end();

    if (before)
        std::cout << "Before: ";
    else
        std::cout << "After: ";
    for (typename C::const_iterator it = cont.begin(); it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
template <typename C>
void sortCont(C& cont)
{
    (void)cont;
}
#include <unistd.h>

void    sortWrapper(std::deque<int>& deque, std::vector<int>& vec)
{
    struct timeval t1, t2;

    printCont(vec, true);
    gettimeofday(&t1, NULL);
    sleep(1); // sort vec
    sortCont(vec);
    gettimeofday(&t2, NULL);
    printCont(vec, false);
    std::cout << "Time taken to process a range of " << vec.size() << " elements with std::vector<int> : " 
     << (t2.tv_usec - t1.tv_usec) << " us" << std::endl;

    gettimeofday(&t1, NULL);
    sortCont(deque);
    gettimeofday(&t2, NULL);
    std::cout << "Time taken to process a range of " << deque.size() << " elements with std::deque<int> : " 
     << (t2.tv_usec - t1.tv_usec) << " us" << std::endl;
}

int main(int argc, char **argv)
{
    std::deque<int>  maind;
    std::vector<int> mainv;
    (void)argc;

    if (parseInput(argv, maind) == 1 || parseInput(argv, mainv))
        return 1;
    sortWrapper(maind, mainv);
    return 0;
}
