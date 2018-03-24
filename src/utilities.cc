#include "utilities.h"

std::vector<std::string> split(std::string strtem, char a) {
  std::vector<std::string> strvec;

  std::string::size_type pos1, pos2;
  pos2 = strtem.find(a);
  pos1 = 0;
  while (std::string::npos != pos2) {
    strvec.push_back(strtem.substr(pos1, pos2 - pos1));

    pos1 = pos2 + 1;
    pos2 = strtem.find(a, pos1);
  }
  strvec.push_back(strtem.substr(pos1));
  return strvec;
}
