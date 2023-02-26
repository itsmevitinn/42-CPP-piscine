#include "Scalar.hpp"

Scalar::Scalar(void) {
}

Scalar::Scalar(std::string string) {
  if (string.size() == 1 && isprint(string[0]) && !isdigit(string[0])) {
    this->_charValue = "'";
    this->_charValue += static_cast<char>(string[0]);
    this->_charValue += "'";
    std::cout << "char: " << this->_charValue << std::endl;
    std::cout << "int: " << static_cast<int>(string[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(string[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(string[0]) << ".0" << std::endl;
    return;
  }
  if (string.empty() || this->isInvalid(string)) {
    throw Scalar::InvalidInput();
  }
  this->_intValue = std::atoi(string.c_str());
  this->_floatValue = static_cast<float>(std::atof(string.c_str()));
  this->_doubleValue = std::atof(string.c_str());
  if (this->_charValue.empty() && !isprint(this->_intValue)) {
    this->_charValue = "Non displayable";
  }
  if (this->_charValue.empty() && isprint(this->_intValue)) {
    this->_charValue = "'";
    this->_charValue += static_cast<char>(this->_intValue);
    this->_charValue += "'";
  }
  if (this->isPseudoLiteral(string)) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "char: " << this->_charValue << std::endl;
    std::cout << "int: " << this->_intValue << std::endl;
  }
  if (this->_floatValue - static_cast<int>(this->_floatValue) == 0) {
    std::cout << "float: " << this->_floatValue << ".0f" << std::endl;
    std::cout << "double: " << this->_doubleValue << ".0" << std::endl;
  } else {
    std::cout << "float: " << this->_floatValue << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(this->_doubleValue) << std::endl;
  }
}

Scalar::~Scalar(void) {
}

Scalar::Scalar(const Scalar& instance) : _charValue(instance._charValue), _intValue(instance._intValue), _floatValue(instance._floatValue), _doubleValue(instance._doubleValue) {
}

Scalar& Scalar::operator=(const Scalar& instance) {
  this->_charValue = instance._charValue;
  this->_intValue = instance._intValue;
  this->_floatValue = instance._floatValue;
  this->_doubleValue = instance._doubleValue;
  return (*this);
}

const char* Scalar::InvalidInput::what() const throw() {
  return ("Invalid string!");
}

int Scalar::isPseudoLiteral(std::string string) {
  std::string pseudo[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
  for (int i = 0; i < 6; i++) {
    if (string == pseudo[i]) {
      return (1);
    }
  }
  return (0);
}

int Scalar::isInvalid(std::string string) {
  int dots = 0;
  if (std::atof(string.c_str()) > std::numeric_limits<int>::max() || std::atof(string.c_str()) < std::numeric_limits<int>::min()) {
    return (1);
  }
  for (unsigned long i = 0; i < string.size(); i++) {
    if (string[i] == '.') {
      dots++;
    }
  }
  for (unsigned long i = 0; i < string.size(); i++) {
    if (dots > 1) {
      return (1);
    } else if (!std::isdigit(string[i]) && string[i] != 'f' && string[i] != '.' && !this->isPseudoLiteral(string)) {
      return (1);
    }
  }
  return (0);
}
