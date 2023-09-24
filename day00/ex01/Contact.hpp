#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    private:
        std::string	FirstName;
        std::string	LastName;
        std::string	Nickname;
        std::string DarkestSecret;
    public:
        Contact();
        ~Contact();
        std::string		GetFirstName(void);
        std::string		GetLastName(void);
        std::string		GetNickname(void);
        std::string		GetDarkestSecret(void);
        void	    	SetFirstName(std::string FirstName);
        void	    	SetLastName(std::string LastName);
        void	    	SetNickname(std::string Nickname);
        void	    	SetDarkestSecret(std::string DarkestSecret);
        void        	PrintContact(int Index);
};

#endif