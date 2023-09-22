#include "PhoneBook.hpp"

int		main(void)
{
    std::string	input;
    PhoneBook	phonebook;

    while (1)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);
        if (input == "EXIT" || std::cin.eof())
            break ;
        else if (input == "ADD")
            phonebook.add();
        else if (input == "SEARCH")
            phonebook.search();
    }
    return (0);
}