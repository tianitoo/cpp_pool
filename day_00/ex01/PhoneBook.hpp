#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class PhoneBook
{
    private:
        Contact		contacts[8];
        int			contactindex;

    public:
        PhoneBook();
        ~PhoneBook();

        void		add(void);
        void		search(void);
        void		print_contacts();
        int&		getIndex(void);
        Contact&	getContacts(void);
        Contact&	getContact(int index);
        void        setIndex(int index);
        void        setContacts(Contact contact, int index);
};


#endif