#ifndef RPN_HPP
#define RPN_HPP

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stack>

class RPN
{
private:

    std::stack<int> _stack;

public:

    RPN();
    RPN(const RPN& data);
    RPN& operator=(const RPN& data);
    ~RPN();

    void processInput(const std::string &str);
    bool isNumber(const std::string& token) const;
    bool isOperator(const std::string& token) const;
    void executeOperation(char simbol);

    void printStack() const;
};

#endif