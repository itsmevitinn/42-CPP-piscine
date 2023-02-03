#ifndef SEDINFO_HPP
#define SEDINFO_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class sedInfo {
 private:
  std::ifstream _infile;
  std::ofstream _outfile;
  std::string _replaced;
  std::string _replacer;

 public:
  sedInfo(std::string infile, std::string replaced, std::string replacer);
  void setReplaced(std::string replaced);
  void setReplacer(std::string replacer);
  void setInfile(std::string infile);
  void setOutfile(std::string outfile);
  std::ifstream& getInfile(void);
  std::ofstream& getOutfile(void);
  std::string getReplaced(void);
  void writeToOutfile(std::string outfileContent);
  ~sedInfo(void);
};

#endif
