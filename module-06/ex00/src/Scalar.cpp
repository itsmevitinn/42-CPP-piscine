#include "Scalar.hpp"

Scalar::Scalar(void) {
}

Scalar::Scalar(std::string string) {
  if (string.empty()) {
    throw Scalar::InvalidInput();
  }
  if (string.size() == 1 && isprint(string[0]) && !isdigit(string[0])) {
    this->printCharLiteral(string[0]);
    return;
  }
  this->printChar(string);
  this->printInt(string);
  this->printFloat(string);
  this->printDouble(string);
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
  return ("Invalid input!");
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

int Scalar::isOverflow(std::string string) {
  if (isPseudoLiteral(string)) {
    return (0);
  } else if (std::atof(string.c_str()) > std::numeric_limits<int>::max() || std::atof(string.c_str()) < std::numeric_limits<int>::min()) {
    return (1);
  }
  return (0);
}

void Scalar::printCharLiteral(char letter) {
  this->_charValue = "'";
  this->_charValue += static_cast<char>(letter);
  this->_charValue += "'";
  std::cout << "char: " << this->_charValue << std::endl;
  std::cout << "int: " << static_cast<int>(letter) << std::endl;
  std::cout << "float: " << static_cast<float>(letter) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(letter) << ".0" << std::endl;
}

void Scalar::printChar(std::string string) {
  this->_intValue = std::atoi(string.c_str());
  if (isPseudoLiteral(string)) {
    std::cout << "char: impossible" << std::endl;
  } else if (this->_intValue >= 32 && this->_intValue <= 126) {
    this->_charValue = "'";
    this->_charValue += static_cast<char>(this->_intValue);
    this->_charValue += "'";
    std::cout << "char: " << this->_charValue << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
}

void Scalar::printInt(std::string string) {
  if (this->isPseudoLiteral(string) || this->isOverflow(string)) {
    std::cout << "int: impossible" << std::endl;
  } else {
    this->_intValue = std::atoi(string.c_str());
    std::cout << "int: " << this->_intValue << std::endl;
  }
}

void Scalar::printDouble(std::string string) {
  this->_doubleValue = std::atof(string.c_str());
  if (this->_floatValue - static_cast<int>(this->_floatValue) == 0) {
    std::cout << "double: " << this->_doubleValue << ".0" << std::endl;
  } else {
    std::cout << "double: " << static_cast<double>(this->_doubleValue) << std::endl;
  }
}

void Scalar::printFloat(std::string string) {
  this->_floatValue = static_cast<float>(std::atof(string.c_str()));
  if (this->_floatValue - static_cast<int>(this->_floatValue) == 0) {
    std::cout << "float: " << this->_floatValue << ".0f" << std::endl;
  } else {
    std::cout << "float: " << this->_floatValue << "f" << std::endl;
  }
}
