#include "Scalar.hpp"

int main(int argc, char** argv) {
  if (argc == 2) {
    try {
      Scalar convert(argv[1]);
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  } else {
    std::cerr << "You must use only 1 argument! (e.g.: ./scalar 43)" << std::endl;
  }
  return (0);
}
