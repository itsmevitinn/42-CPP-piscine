#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private:
		int _contactsSize;
		int _index;
		Contact _contactList[8];
	public:
		PhoneBook(void);
		void	addContact(Contact newContact);
		void	printPhoneBook(void);
};

#endif
