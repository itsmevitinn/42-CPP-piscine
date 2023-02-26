#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

typedef struct {
  std::string name;
  std::string country;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
