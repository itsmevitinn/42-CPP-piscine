#include "BitcoinExchange.hpp"

void getDatabaseContent(std::map<std::string, float>& database) {
  std::ifstream database_file;
  std::string line;
  std::string key;
  std::string cobaia;
  float value;

  (void)value;
  database_file.open("data.csv");
  if (!database_file.is_open())
    throw("Can't open database file!");
  do {
    key = line.substr(0, 10);
    database.insert(std::pair<std::string, float>(key, 0));
  } while (std::getline(database_file, line));
}

int main(int argc, char** argv) {
  std::map<std::string, float> database;
  std::ifstream input_file;
  std::string line;

  try {
    if (argc != 2)
      throw("Only the input file as argument!");
    getDatabaseContent(database);
    input_file.open(argv[1]);
    if (!input_file.is_open())
      throw("No such file or directory");
    do {
      (void)line;
    } while (std::getline(input_file, line));
  } catch (char const* error) {
    std::cout << error << std::endl;
  }
}