#include "Fixed.hpp"

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  this->_fixedPointNumber = 0;
}

Fixed::Fixed(const int number) {
  std::cout << "Int constructor called" << std::endl;
  // pegamos o number e "multiplicamos" por 256 (shiftando 8 bits a esquerda) para convertermos p/ fixed point
  // o fixed point ira considerar todos os bits desse numero como decimal, e apos somar os valores decimais que representam esses bits, ira dar o valor na "forma" inteira
  this->_fixedPointNumber = number << this->_bits;
}

Fixed::Fixed(const float number) {
  std::cout << "Float constructor called" << std::endl;
  // iremos shiftar o numero 1 8x para esquerda (p/ pular os bits da fracao) , apos isso, iremos multiplicar esse resultado pelo float que estamos recebendo, p/ representar o valor em fixed point (fixed point eh inteiro)
  // apos pegarmos o valor dessa multiplicacao, que ira retornar um float, iremos arredondar esse float p/ armazenar em nosso fixed point, que eh um inteiro
  // porem, caso queiramos printar o valor do nosso fixed point como float, nos conseguimos pois os bits que representam a fracao estarao armazenados no int, ja que o tamanho do int
  // eh 4 bytes como o do float tambem eh
  this->_fixedPointNumber = roundf(number * (1 << this->_bits));
}

float Fixed::toFloat(void) const {
  return ((float)this->_fixedPointNumber / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const {
  return ((int)this->_fixedPointNumber >> this->_bits);
}

Fixed& Fixed::operator=(const Fixed& instance) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_fixedPointNumber = instance._fixedPointNumber;
  return (*this);
}

Fixed::Fixed(const Fixed& instance) {
  std::cout << "Copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_fixedPointNumber = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& instance){
  os << instance.toFloat();
  return (os);
}