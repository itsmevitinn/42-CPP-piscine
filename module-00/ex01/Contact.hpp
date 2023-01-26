#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <csignal>

class Contact {
 private:
  int _id;
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;

 public:
  void setId(int id);
  void setFirstName(std::string firstName);
  void setLastName(std::string lastName);
  void setNickname(std::string nickname);
  void setPhoneNumber(std::string phoneNumber);
  void setDarkestSecret(std::string darkestSecret);

  int getId(void);
  std::string getFirstName(void);
  std::string getLastName(void);
  std::string getNickname(void);
  std::string getPhoneNumber(void);
  std::string getDarkestSecret(void);
};

#endif
