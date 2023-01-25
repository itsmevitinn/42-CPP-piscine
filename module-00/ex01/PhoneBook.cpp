#include "PhoneBook.hpp"

#include "Contact.hpp"

void PhoneBook::addContact(Contact newContact) {
  newContact.setId(this->_index + 1);
  this->_contactList[this->_index++] = newContact;
  // a lista so ira crescer quando nao atingir o limite, quando atingir, o novo contato ira sobrepor o mais antigo
  if (this->_contactsSize < 8)
    this->_contactsSize++;
  // resetando o index caso passe do tamanho maximo da lista
  this->_index = this->_index % 8;
  std::cout << "Contact added to PhoneBook!" << std::endl;
}

void PhoneBook::printContacts(void) {
  this->printHeader();
  for (int i = 0; i < this->_contactsSize; i++) {
    std::cout << std::right << std::setw(10) << this->_contactList[i].getId() << "|";
    printColumn(this->_contactList[i].getFirstName());
    printColumn(this->_contactList[i].getLastName());
    printColumn(this->_contactList[i].getNickname());
    std::cout << std::endl;
  }
}

void  PhoneBook::printHeader(void){
  std::cout << std::right << std::setw(10) << "INDEX" << "|";
  std::cout << std::right << std::setw(10) << "FIRST NAME" << "|";
  std::cout << std::right << std::setw(10) << "LAST NAME" << "|";
  std::cout << std::right << std::setw(10) << "NICKNAME" << "|" << std::endl;
}

void  PhoneBook::printColumn(std::string info){
  if (info.size() > 10)
    info = info.substr(0,9) + '.';
  std::cout << std::right << std::setw(10) << info << "|";
}

void PhoneBook::contactInfo(int contactId) {
  for (int i = 0; i < this->_contactsSize; i++) {
    if (contactId == this->_contactList[i].getId()) {
      std::cout << std::endl;
      std::cout << "Here is your contact info!" << std::endl;
      std::cout << this->_contactList[i].getId() << " | ";
      std::cout << this->_contactList[i].getFirstName() << " | ";
      std::cout << this->_contactList[i].getLastName() << " | ";
      std::cout << this->_contactList[i].getNickname() << " | ";
      std::cout << this->_contactList[i].getPhoneNumber() << " | ";
      std::cout << this->_contactList[i].getDarkestSecret() << std::endl;
      return;
    }
  }
  std::cout << "Contact not found!" << std::endl;
}

PhoneBook::PhoneBook(void) {
  this->_index = 0;
  this->_contactsSize = 0;
  return;
}
