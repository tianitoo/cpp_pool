#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
    this->ContactIndex = 0;
    this->ContactNumber = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::Add()
{
    Contact             Contact;
    std::string         FirstName;
    std::string         LastName;
    std::string         Nickname;
    std::string         DarkestSecret;
    
    std::cout << "Enter first name: ";
    std::cin >> FirstName;
    std::cout << "Enter last name: ";
    std::cin >> LastName;
    std::cout << "Enter nickname: ";
    std::cin >> Nickname;
    std::cout << "Enter darkest secret: ";
    std::cin >> DarkestSecret;
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
}

void	PhoneBook::Search(void)
{
    int			Index;

    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
    Index = 0;
    PrintContacts();
    ShowContact();
}

void    PhoneBook::ShowContact()
{
    int			Index;
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string DarkestSecret;
    
    while (1)
    {
        std::cout << "Enter index: ";
        if (std::cin >> Index){
            if (Index >= 0 && Index <= 7 && Index < this->GetContactNumber()) {
                std::cout << std::left << std::setw(17) << "First name" << ": " << this->GetContact(Index).GetFirstName() << std::endl;
                std::cout << std::left << std::setw(17) << "Last name" << ": " << this->GetContact(Index).GetLastName() << std::endl;
                std::cout << std::left << std::setw(17) << "Nickname" << ": " << this->GetContact(Index).GetNickname() << std::endl;
                std::cout << std::left << std::setw(17) << "Darkest secret" << ": " << this->GetContact(Index).GetDarkestSecret() << std::endl;
                break ;
            }
            else
                std::cout << "Invalid index" << std::endl;
        }
        else
            std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

void PhoneBook::PrintContacts() {
    for (int index = 0; index < 8; index++) {
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