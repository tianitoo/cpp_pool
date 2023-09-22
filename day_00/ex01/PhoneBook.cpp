#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
    this->contactindex = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
    Contact             contact;
    std::string         first_name;
    std::string         last_name;
    std::string         nickname;
    
    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    std::cout << std::endl;
    contact.setFirstName(first_name);
    contact.setLastName(last_name);
    contact.setNickname(nickname);

    if (this->getIndex() == 8)
        this->setIndex(0);
    this->setContacts(contact, this->getIndex());
    this->setIndex(this->getIndex() + 1);
}

void	PhoneBook::search(void)
{
    int			index;
    std::string	input;
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
    index = 0;
    print_contacts();
}

void PhoneBook::print_contacts() {
    for (int index = 0; index < 8; index++) {
        this->getContact(index).print_contact(index);
    }
}

int&	PhoneBook::getIndex(void)
{
    return (this->contactindex);
}

Contact&	PhoneBook::getContacts(void)
{
    return (*this->contacts);
}

void         PhoneBook::setIndex(int index)
{
    this->contactindex = index;
}

void     PhoneBook::setContacts(Contact contact, int index)
{
    this->contacts[index] = contact;
}

Contact&	PhoneBook::getContact(int index)
{
    return (this->contacts[index]);
}