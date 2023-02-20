#include "Contact.hpp"
#include "PhoneBook.hpp"

void getInput(std::string output, std::string &buffer);

void createContact(PhoneBook &myPhoneBook) {
  Contact newContact;
  std::string buffer;

  getInput("First name: ", buffer);
  newContact.setFirstName(buffer);

  getInput("Last name: ", buffer);
  newContact.setLastName(buffer);

  getInput("Nickname: ", buffer);
  newContact.setNickname(buffer);

  getInput("Phone number: ", buffer);
  newContact.setPhoneNumber(buffer);

  getInput("Darkest secret: ", buffer);
  newContact.setDarkestSecret(buffer);

  myPhoneBook.addContact(newContact);
}

void getInput(std::string output, std::string &buffer) {
  do {
    std::cout << output << std::endl;
    std::cout << "-> ";
    std::getline(std::cin, buffer);
  } while (buffer.empty());
}

void searchContact(PhoneBook &myPhoneBook) {
  std::string contactId;

  myPhoneBook.printContacts();
  std::cout << std::endl
            << "ID to search a contact: " << std::endl;
  std::cout << "-> ";
  std::getline(std::cin, contactId);
  try {
    myPhoneBook.contactInfo(stoi(contactId));
  } catch (...) {
    std::cout << "Invalid ID!" << std::endl;
  }
}

int main(void) {
  PhoneBook myPhoneBook;
  std::string option;

  std::cout << std::endl
            << "Welcome to your awesome phonebook!" << std::endl;
  while (42 && !std::cin.eof()) {
    std::cout << std::endl
              << "Choose one of the options below!" << std::endl;
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
