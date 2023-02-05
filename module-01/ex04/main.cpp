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
      // essa diferenca ira escrever da onde parou a ultima string ate antes do comeco da string que ira ser substituida
      outfileContent.append(line, offset, indexToReplace - offset);
      // apos copiar os caracteres remanescentes ate antes do data.getReplaced(), vai "substituir" onde deveria ser a string data.getReplaced() pela nova string
      outfileContent += data.getReplacer();
      // aqui ira avancar o offset para depois da string que foi substituida
      offset = indexToReplace + data.getReplaced().length();
    }
    outfileContent.append(line, offset, std::string::npos);
    data.writeToOutfile(outfileContent);
  }
}

int main(int argc, char** argv) {
  try {
    if (argc == 4) {
      sedInfo data(argv[1], argv[2], argv[3]);
      data.setOutfile(argv[1]);
      getOutfileContent(data);
    } else {
      throw(std::string("Invalid numbers of argc!"));
    }
  } catch (std::string error) {
    std::cerr << error << std::endl;
    return(0);
  }
}
