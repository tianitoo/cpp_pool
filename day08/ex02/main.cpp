#include "MutantStack.hpp"
#include <iostream>

int main()
{
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "top: " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "size: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);

        //[...]
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "---------------------" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(42);
        mstack.push(21);
        mstack.push(84);
        mstack.push(168);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;
        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;
        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;
        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;
    }
    return 0;
}