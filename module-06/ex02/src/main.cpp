#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void) {
  Base* pointer = generate();
  Base* refPointer = generate();
  Base& reference = *refPointer;

  identify(pointer);
  identify(reference);

  delete pointer;
  delete refPointer;
  return (0);
}

Base* generate(void) {
  Base* derived;
  srand((unsigned)time(NULL));
  switch (rand() % 8) {
    case 0:
      derived = new A();
      break;
    case 1:
      derived = new B();
      break;
    case 2:
      derived = new C();
      break;
    default:
      derived = NULL;
  }
  return (derived);
}

void identify(Base* p) {
  std::cout << "Pointer identified as: ";
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  } else {
    std::cerr << "Bad pointer cast" << std::endl;
  }
}

void identify(Base& p) {
  std::cout << "Reference identified as: ";
  try {
    if (dynamic_cast<A*>(&p)) {
      std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(&p)) {
      std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(&p)) {
      std::cout << "C" << std::endl;
    } else {
      throw static_cast<std::string>("Bad reference cast");
    }
  } catch (std::string error) {
    std::cerr << error << std::endl;
  }
}
