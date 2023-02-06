#include "sedInfo.hpp"

void getOutfileContent(sedInfo& data) {
  std::string outfileContent;
  std::string line;
  size_t indexToReplace;
  int offset;

  while (std::getline(data.getInfile(), line)) {
    outfileContent.clear();
    offset = 0;
    while ((indexToReplace = line.find(data.getReplaced(), offset)) != std::string::npos) {
      outfileContent.append(line, offset, indexToReplace - offset);
      outfileContent += data.getReplacer();
      offset = indexToReplace + data.getReplaced().length();
    }
    outfileContent.append(line, offset, std::string::npos);
    data.writeToOutfile(outfileContent);
  }
}

void check_arguments(int argc, char* replaced) {
  if (argc != 4)
    throw(std::string("Invalid numbers of argc!"));
  else if (!*replaced) {
    throw(std::string("Content to be replaced can't be a empty string!"));
  }
}

int main(int argc, char** argv) {
  try {
    check_arguments(argc, argv[2]);
    sedInfo data(argv[1], argv[2], argv[3]);
    data.setOutfile(argv[1]);
    getOutfileContent(data);
  } catch (std::string error) {
    std::cerr << error << std::endl;
    return (0);
  }
}
