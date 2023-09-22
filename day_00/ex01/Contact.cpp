#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::getFirstName() const {
    return first_name;
}

std::string Contact::getLastName() const {
    return last_name;
}

std::string Contact::getNickname() const {
    return nickname;
}

void Contact::setFirstName(const std::string first_name) {
    this->first_name = first_name;
}

void Contact::setLastName(const std::string last_name) {
    this->last_name = last_name;
}

void Contact::setNickname(const std::string nickname) {
    this->nickname = nickname;
}

void    Contact::print_contact(int index)
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << this->getFirstName() << "|";
    std::cout << std::setw(10) << this->getLastName() << "|";
    std::cout << std::setw(10) << this->getNickname() << std::endl;
}