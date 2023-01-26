#include "Contact.hpp"
#include "PhoneBook.hpp"

void createContact(PhoneBook &myPhoneBook) {
  Contact newContact;
  std::string buffer;

  std::cout << "First name: " << std::endl << "-> ";
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
  std::cout << std::endl << "ID to search a contact: " << std::endl;
  std::cout << "-> ";
  std::getline(std::cin, contactId);
  try{
    myPhoneBook.contactInfo(stoi(contactId));
  }
  catch (...){
    std::cout << "Invalid ID!" << std::endl;
  }
}

int main(void) {
  PhoneBook myPhoneBook;
  std::string option;

  std::cout << std::endl << "Welcome to your awesome phonebook!" << std::endl;
  while (42 && !std::cin.eof()) {
    std::cout << std::endl << "Choose one of the options below!" << std::endl;
    std::cout << "ADD | SEARCH | EXIT" << std::endl;
    std::cout << "-> ";
    std::getline(std::cin, option);
    if (option == "ADD")
      createContact(myPhoneBook);
    else if (option == "SEARCH")
      searchContact(myPhoneBook);
    else if (option == "EXIT")
      exit(0);
    else
      std::cout << "Send an invalid option!" << std::endl;
  }
}
