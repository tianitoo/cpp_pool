#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
    this->ContactIndex = 0;
    this->ContactNumber = 0;
}

PhoneBook::~PhoneBook()
{
}

int	PhoneBook::Add()
{
    Contact             Contact;
    std::string         FirstName;
    std::string         LastName;
    std::string         Nickname;
    std::string         DarkestSecret;
    
    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, FirstName) || std::cin.eof())
        return 0;
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, LastName) || std::cin.eof())
        return 0;
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, Nickname) || std::cin.eof())
        return 0;
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, DarkestSecret) || std::cin.eof())
        return 0;
    Contact.SetFirstName(FirstName);
    Contact.SetLastName(LastName);
    Contact.SetNickname(Nickname);
    Contact.SetDarkestSecret(DarkestSecret);

    if (this->GetIndex() == 8)
        this->SetIndex(0);
    this->SetContacts(Contact, this->GetIndex());
    this->SetIndex(this->GetIndex() + 1);
    if (this->GetContactNumber() < 8)
        this->SetContactNumber(this->GetContactNumber() + 1);
    return 1;
}

int	PhoneBook::Search(void)
{
    int			i;

    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
    PrintContacts();
    i = ShowContact();
    return i;
}

int    PhoneBook::ShowContact()
{
    int         Index;
    std::string i;
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string DarkestSecret;

    std::cout << "Enter index: ";
    if (!std::getline(std::cin, i) || std::cin.eof())
        return 0;
    if (i.length() > 1 || (i[0] < '0' || i[0] > '7'))
    {
        std::cout << "Invalid index" << std::endl;
        return 1;
    }
    Index = std::stoi(i);
    if (Index < this->GetContactNumber()) {
        std::cout << std::left << std::setw(17) << "First name" << ": " << this->GetContact(Index).GetFirstName() << std::endl;
        std::cout << std::left << std::setw(17) << "Last name" << ": " << this->GetContact(Index).GetLastName() << std::endl;
        std::cout << std::left << std::setw(17) << "Nickname" << ": " << this->GetContact(Index).GetNickname() << std::endl;
        std::cout << std::left << std::setw(17) << "Darkest secret" << ": " << this->GetContact(Index).GetDarkestSecret() << std::endl;
    }
    else
        std::cout << "Invalid index" << std::endl;
    std::cin.clear();
    return 1;
}

void PhoneBook::PrintContacts() {
    for (int index = 0; index < this->ContactNumber; index++) {
        this->GetContact(index).PrintContact(index);
    }
}

int&	PhoneBook::GetIndex(void)
{
    return (this->ContactIndex);
}

Contact&	PhoneBook::GetContacts(void)
{
    return (*this->Contacts);
}

int&    PhoneBook::GetContactNumber(void)
{
    return (this->ContactNumber);
}

void         PhoneBook::SetIndex(int Index)
{
    this->ContactIndex = Index;
}

void     PhoneBook::SetContacts(Contact Contact, int Index)
{
    this->Contacts[Index] = Contact;
}

Contact&	PhoneBook::GetContact(int Index)
{
    return (this->Contacts[Index]);
}

void    PhoneBook::SetContactNumber(int ContactNumber)
{
    this->ContactNumber = ContactNumber;
}