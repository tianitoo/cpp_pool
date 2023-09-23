#include "PhoneBook.hpp"

int		main(void)
{
    std::string	input;
    PhoneBook	phonebook;

    while (1)
    {
        std::cout << "Enter command: ";
        std::cin >> input;
        if (input == "EXIT" || std::cin.eof())
            break ;
        else if (input == "ADD")
            phonebook.Add();
        else if (input == "SEARCH")
            phonebook.Search();
        else
            std::cout << "Invalid command" << std::endl;
        std::cin.clear();
    }
    return (0);
}