#include "RPN.hpp"

std::stack<int> RPN::_operators;

RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &copy)
{
    (void)copy;
    return *this;
}

void RPN::fillStack(std::string str) {

    std::istringstream ss(str);

    while (ss) {
        std::string token;
        ss >> token;
        if (token.empty())
            break;
        if (token.find_first_not_of("0123456789+-*/") == std::string::npos) {
            if (token.find_first_of("+-*/") != std::string::npos) {
                if (_operators.size() < 2)
                    throw BadSyntax();
                int num2 = _operators.top();
                _operators.pop();
                int num1 = _operators.top();
                _operators.pop();
                int res = operation(num1, num2, token);
                _operators.push(res);
            } else {
                _operators.push(std::stoi(token));
            }
        } else {
            throw InvalidToken();
        }
    }
    if (_operators.size() != 1)
        throw BadSyntax();
    std::cout << _operators.top() << std::endl;
}

void RPN::printStack() {
    std::stack<int> tmp = _operators;
    std::cout << "Stack: " << std::endl;
    while (!tmp.empty()) {
        std::cout << tmp.top() << " ";
        tmp.pop();
    }
    std::cout << std::endl;
}

int RPN::operation(int n1, int n2, std::string op) {
    if (op == "+") {
        return n1 + n2;
    } else if (op == "-") {
        return n1 - n2;
    } else if (op == "*") {
        return n1 * n2;
    } else if (op == "/") {
        return n1 / n2;
    } else {
        throw InvalidToken();
    }
    return 0;
}

