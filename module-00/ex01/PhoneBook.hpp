#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
 private:
  int _contactsSize;
  int _index;
  Contact _contactList[8];

 public:
  PhoneBook(void);
  void addContact(Contact newContact);
  void printContacts(void);
  void contactInfo(int contactId);
  void printHeader(void);
  void printColumn(std::string info);
};

#endif
