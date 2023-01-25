#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

// passando a instancia por referencia
void createContact(PhoneBook &myPhoneBook) {
  Contact newContact;
  std::string buffer;

  std::cout << "First name: " << std::endl << "-> ";
  //getline instead of std::cin cuz getline grep the whole input without truncate
  std::getline(std::cin, buffer);
  newContact.setFirstName(buffer);

  std::cout << "Last name: " << std::endl << "-> ";
  std::getline(std::cin, buffer);
  newContact.setLastName(buffer);

  std::cout << "Nickname: " << std::endl << "-> ";
  std::getline(std::cin, buffer);
  newContact.setNickname(buffer);

  std::cout << "Phone number: " << std::endl << "-> ";
  std::getline(std::cin, buffer);
  newContact.setPhoneNumber(buffer);

  std::cout << "Darkest secret: " << std::endl << "-> ";
  std::getline(std::cin, buffer);
  newContact.setDarkestSecret(buffer);

  myPhoneBook.addContact(newContact);
}

void  searchContact(PhoneBook &myPhoneBook){
  std::string contactId;

  myPhoneBook.printContacts();
  std::cout << std::endl;
  std::cout << "ID to search a contact: " << std::endl << "-> ";
  std::getline(std::cin, contactId);
  myPhoneBook.contactInfo(stoi(contactId));
}

int main(void) {
  PhoneBook myPhoneBook;
  std::string option;

  std::cout << "Welcome to your awesome phonebook!" << std::endl;
  while (42) {
    std::cout << std::endl;
    std::cout << "Choose one of the options below!" << std::endl;
    std::cout << "ADD | SEARCH | EXIT" << std::endl;
    std::cout << "-> ";
    std::getline(std::cin, option);
    std::cout << std::endl;

    if (option == "ADD")
      createContact(myPhoneBook);
    else if (option == "SEARCH")
      searchContact(myPhoneBook);
  }
}
