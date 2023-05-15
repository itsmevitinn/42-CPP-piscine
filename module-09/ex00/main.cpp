#include "BitcoinExchange.hpp"

void getDatabaseContent(std::map<std::string, float>& database) {
  std::ifstream database_file;
  std::string line;
  std::string date;
  float rate;

  database_file.open("data.csv");
  if (!database_file.is_open())
    throw("Can't open database file!");
  do {
    std::getline(database_file, line);
    date = line.substr(0, line.find(","));
    if (!date.empty() && date != "date") {
      rate = atof(line.substr(line.find(",") + 1, std::string::npos).c_str());
      database.insert(std::pair<std::string, float>(date, rate));
    }
  } while (!line.empty());
}

int isValidDate(std::string date) {
  int year;
  int month;
  int day;

  if (date > "2022-03-29" || date < "2009-01-02")
    return (0);

  sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day);

  if (month < 1 || month > 12 || day < 1 || day > 31)
    return (0);
  if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      if (day > 29)
        return (0);
    } else {
      if (day > 28)
        return (0);
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      return (0);
    }
  }
  return (1);
}

int isValidValue(float value) {
  if (value < 0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return (0);
  } else if (value > 1000) {
    std::cerr << "Error: too large a number." << std::endl;
    return (0);
  }
  return (1);
}

void printBitcoinValue(std::string date, float value, std::map<std::string, float>& database) {
  std::map<std::string, float>::iterator lower_than_data;

  if (database.find(date) != database.end()) {
    std::cout << date << " => " << value << " = " << database[date] * value << std::endl;
  } else {
    lower_than_data = database.upper_bound(date);
    if (lower_than_data == database.begin())
      std::cerr << "Equal or smaller date not found!" << std::endl;
    else {
      --lower_than_data;
      std::cout << date << " => " << value << " = " << lower_than_data->second * value << std::endl;
    }
  }
}

void getInputContent(std::map<std::string, float>& database, std::string filename) {
  std::ifstream input_file;
  std::string date;
  std::string line;
  char content[1024];
  float value;

  input_file.open(filename);
  if (!input_file.is_open())
    throw("Invalid input file!");
  while (input_file.getline(content, 1024)) {
    date = strtok(content, " |");
    if (date == "date")
      continue;
    if (isValidDate(date)) {
      value = atof(strtok(NULL, " |"));
      if (isValidValue(value))
        printBitcoinValue(date, value, database);
    } else {
      std::cerr << "Error: bad input => " << date << std::endl;
    }
  }
}

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
