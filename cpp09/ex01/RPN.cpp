/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:42:55 by ramarti2          #+#    #+#             */
/*   Updated: 2026/07/07 18:43:07 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool    isoperator(char c, std::stack<float>& stack)
{
    if (c == '/' && stack.top() == 0)
    {
        std::cerr << "Can't divide by 0." << std::endl;
        return false;
    }
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return true;
    return false;
}

void    eval_operation(std::stack<float>& stack, char operation)
{
    float copy;
    float result;

    copy = stack.top();
    stack.pop();
    
    switch (operation)
    {
        case '+':
            result = stack.top() + copy;
            break ;
        case '-':
            result = stack.top() - copy;
            break ;
        case '/':
            result = stack.top() / copy;
            break ;
        case '*':
            result = stack.top() * copy;
            break ;
    }
    stack.pop();
    stack.push(result);
}

int rpn(char *expr)
{
    std::stack<float> stack;

    for (int i = 0; expr[i]; i++)
    {
        if (std::isdigit(expr[i]))
        {
            stack.push(expr[i] - '0');
        }
        else if (isoperator(expr[i], stack) && stack.size() >= 2)
        {
            eval_operation(stack, expr[i]);
        }
        else if (expr[i])
        {
            std::cerr << "Error: invalid character." << std::endl;
            return 1;
        }
        if (expr[i + 1] && expr[i + 2])
            i++;
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error: not enough operators" << std::endl;
        return 1;
    }
    std::cout << stack.top() << std::endl;
    return 0;
}
