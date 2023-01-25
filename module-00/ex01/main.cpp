#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

//ponteiro p/ nao perder a referencia da instancia
void createContact(PhoneBook *myPhoneBook) {
  Contact newContact;
  std::string buffer;

  std::cout << "First name: ";
  std::cin >> buffer;
  newContact.setFirstName(buffer);

  std::cout << "Last name: ";
  std::cin >> buffer;
  newContact.setLastName(buffer);

  std::cout << "Nickname: ";
  std::cin >> buffer;
  newContact.setNickname(buffer);

  std::cout << "Phone number: ";
  std::cin >> buffer;
  newContact.setPhoneNumber(buffer);

  std::cout << "Darkest secret: ";
  std::cin >> buffer;
  newContact.setDarkestSecret(buffer);

	myPhoneBook->addContact(newContact);
}

int main(void) {
	PhoneBook myPhoneBook;
  std::string option;

  std::cout << "Welcome to your awesome phonebook!" << std::endl;
  while (42) {
    std::cout << "Choose one of the options below!" << std::endl;
    std::cout << "ADD | SEARCH | EXIT" << std::endl;
    std::cout << std::endl << "Option: ";
    std::cin >> option;

    if (option == "ADD")
			createContact(&myPhoneBook);
  }
}
