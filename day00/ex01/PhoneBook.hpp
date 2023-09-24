#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class PhoneBook
{
    private:
        Contact		Contacts[8];
        int			ContactIndex;
        int         ContactNumber;

    public:
        PhoneBook();
        ~PhoneBook();

        void		Add(void);
        void		Search(void);
        void		PrintContacts();
        int&		GetIndex(void);
        int&        GetContactNumber(void);
        Contact&	GetContacts(void);
        Contact&	GetContact(int Index);
        void        SetIndex(int Index);
        void        SetContacts(Contact Contact, int Cndex);
        void        SetContactNumber(int ContactNumber);
        void        ShowContact(); 
};


#endif