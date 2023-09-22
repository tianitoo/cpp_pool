#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    private:
        std::string	first_name;
        std::string	last_name;
        std::string	nickname;
    public:
        Contact();
        ~Contact();
        std::string		getFirstName(void) const;
        std::string		getLastName(void) const;
        std::string		getNickname(void) const;
        void	    	setFirstName(std::string first_name);
        void    		setLastName(std::string last_name);
        void    		setNickname(std::string nickname);
        void    		print_contact(int index);
};

#endif