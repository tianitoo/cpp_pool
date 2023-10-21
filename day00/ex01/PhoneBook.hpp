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

        int 		Add(void);
        int		    Search(void);
        int         ShowContact(); 
        void		PrintContacts();
        int&        GetContactNumber(void);
        void        SetContactNumber(int ContactNumber);
        Contact&	GetContact(int Index);
        int&		GetIndex(void);
        void        SetIndex(int Index);
        Contact&	GetContacts(void);
        void        SetContacts(Contact Contact, int Cndex);
};


#endif