#include "PhoneBook.hpp"

#include "Contact.hpp"

void PhoneBook::addContact(Contact newContact) {
  this->_contactList[this->_index++] = newContact;
  //a lista so ira crescer quando nao atingir o limite, quando atingir, o novo contato ira sobrepor o mais antigo
  if (this->_contactsSize < 8)
    this->_contactsSize++;
  //resetando o index caso passe do tamanho maximo da lista
  this->_index = this->_index % 8;
  std::cout << "Contact added to PhoneBook!" << std::endl;
  std::cout << "Contacts size: " << this->_contactsSize << std::endl;
  this->printPhoneBook();
}

void PhoneBook::printPhoneBook(void) {
  std::cout << "Here is your phonebook!" << std::endl;
  for (int i = 0; i < this->_contactsSize; i++) {
    std::cout << this->_contactList[i].getFirstName() << " | ";
    std::cout << this->_contactList[i].getLastName() << " | ";
    std::cout << this->_contactList[i].getNickname() << " | ";
    std::cout << this->_contactList[i].getPhoneNumber() << " | ";
    std::cout << this->_contactList[i].getDarkestSecret() << std::endl;
  }
}

PhoneBook::PhoneBook(void) {
  this->_index = 0;
  this->_contactsSize = 0;
  return;
}
