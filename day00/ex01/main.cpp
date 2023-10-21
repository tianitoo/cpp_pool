#include "PhoneBook.hpp"

int		main(void)
{
    std::string	input;
    PhoneBook	phonebook;
    int         i;

    i = 1;
    while (i)
    {
        std::cout << "Enter command: ";
        if (!std::getline(std::cin, input) || input == "EXIT" || std::cin.eof())
            break ;
        else if (input == "ADD")
            i = phonebook.Add();
        else if (input == "SEARCH")
            i = phonebook.Search();
        else
            std::cout << input << "Invalid command" << std::endl;
        std::cin.clear();
    }
    return (0);
}