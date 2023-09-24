#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::GetFirstName() {
    return FirstName;
}

std::string Contact::GetLastName() {
    return LastName;
}

std::string Contact::GetNickname() {
    return Nickname;
}

std::string Contact::GetDarkestSecret() {
    return DarkestSecret;
}

void Contact::SetFirstName(std::string FirstName) {
    this->FirstName = FirstName;
}

void Contact::SetLastName(std::string LastName) {
    this->LastName = LastName;
}

void Contact::SetNickname(std::string Nickname) {
    this->Nickname = Nickname;
}

void Contact::SetDarkestSecret(std::string DarkestSecret) {
    this->DarkestSecret = DarkestSecret;
}

void    Contact::PrintContact(int Index)
{
    std::string FirstName;
    std::string LastName;
    std::string Nickname;

    FirstName = this->GetFirstName();
    LastName = this->GetLastName();
    Nickname = this->GetNickname();
    if (FirstName.length() > 10)
        FirstName = FirstName.substr(0, 9) + ".";
    if (LastName.length() > 10)
        LastName = LastName.substr(0, 9) + ".";
    if (Nickname.length() > 10)
        Nickname = Nickname.substr(0, 9) + ".";
    std::cout << std::setw(10) << Index << "|";
    std::cout << std::setw(10) << FirstName << "|";
    std::cout << std::setw(10) << LastName << "|";
    std::cout << std::setw(10) << Nickname << std::endl;
}