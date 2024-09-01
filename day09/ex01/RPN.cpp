#include "RPN.hpp"

std::stack<std::string> RPN::_operators;

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

    std::istringstream ss({str.rbegin(), str.rend()});

    while (ss) {
        std::string token;
        ss >> token;
        if (token.empty())
            break;
        if (token == "+" || token == "-" || token == "*" || token == "/" || token.find_first_not_of("0123456789") == std::string::npos) {
            _operators.push(token);
        } else {
            throw InvalidToken();
        }
    }
}

void RPN::printStack() {
    std::stack<std::string> tmp = _operators;
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
    }
    return 0;
}

void RPN::calculate() {
    int result = 0;
    // bool lastIsOperator = false;
    if (_operators.top().find_first_not_of("0123456789") != std::string::npos) {
        throw BadSyntax();
    }
    result = std::stoi(_operators.top());
    _operators.pop();

    while (!_operators.empty()) {
    // printStack();
        int number;
        if (_operators.top().find_first_not_of("0123456789") != std::string::npos) {
            throw BadSyntax();
        }
        number = std::stoi(_operators.top());
        _operators.pop();
        if (_operators.empty()) {
            throw BadSyntax();
        }
        if (_operators.top() == "+" || _operators.top() == "-" || _operators.top() == "*" || _operators.top() == "/") {
            result = operation(result, number, _operators.top());
            _operators.pop();
        } else if (_operators.top().find_first_not_of("0123456789") == std::string::npos) {
            int number2 = std::stoi(_operators.top());
            _operators.pop();
            if (_operators.empty()) {
                throw BadSyntax();
            }
            if (_operators.top() == "+" || _operators.top() == "-" || _operators.top() == "*" || _operators.top() == "/") {
                number = operation(number, number2, _operators.top());
                _operators.pop();
                result = operation(result, number, _operators.top());
                _operators.pop();
            } else {
                throw BadSyntax();
            }
        }
    }
    std::cout << result << std::endl;
}