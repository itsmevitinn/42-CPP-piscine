#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  std::map<std::string, float> database;
  std::string line;

  try {
    if (argc != 2)
      throw("Only the input file as argument!");
    getDatabaseContent(database);
    getInputContent(database, argv[1]);
  } catch (char const* error) {
    std::cout << error << std::endl;
  }
}
