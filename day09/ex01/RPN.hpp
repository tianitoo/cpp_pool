#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
#include <limits>
#include <iomanip>

class RPN
{
public:
    RPN();
    RPN(const RPN &copy);
    ~RPN();
    RPN &operator=(const RPN &copy);

    static void fillStack(std::string str);
    static void calculate();
    static void printStack();
    static int operation(int n1, int n2, std::string op);

    class InvalidToken : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Error: invalid token";
        }
    };

    class BadSyntax : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Error: bad syntax";
        }
    };

private:
    static std::stack<int> _operators;
};