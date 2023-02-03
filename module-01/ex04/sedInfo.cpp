#include "sedInfo.hpp"

sedInfo::sedInfo(std::string infile, std::string replaced, std::string replacer) {
  this->setInfile(infile);
  this->setReplaced(replaced);
  this->setReplacer(replacer);
}

void sedInfo::setReplaced(std::string replaced) {
  this->_replaced = replaced;
}

void sedInfo::setReplacer(std::string replacer) {
  this->_replacer = replacer;
}

void sedInfo::setInfile(std::string infile) {
  this->_infile.open(infile);
	if (!this->_infile.is_open())
		throw(infile + ": No such file or directory");
}

sedInfo::~sedInfo(void) {
  this->_infile.close();
  this->_outfile.close();
}

void sedInfo::setOutfile(std::string outfile) {
  this->_outfile.open(outfile + ".replace");
	if (!this->_outfile.is_open())
		throw("Cannot open file: " + outfile);
}

std::ifstream& sedInfo::getInfile(void) {
  return (this->_infile);
}

std::ofstream& sedInfo::getOutfile(void) {
  return (this->_outfile);
}

std::string sedInfo::getReplaced(void) {
  return (this->_replaced);
}

void sedInfo::writeToOutfile(std::string outfileContent) {
	this->getOutfile() << outfileContent << std::endl;
}
