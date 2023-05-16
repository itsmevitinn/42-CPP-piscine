#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void getDatabaseContent(std::map<std::string, float>& database);
void getInputContent(std::map<std::string, float>& database, std::string filename);
int isValidDate(std::string date);
int isValidValue(float value);
void printBitcoinValue(std::string date, float value, std::map<std::string, float>& database);

#endif
