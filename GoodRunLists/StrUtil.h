#ifndef STRUTIL
#define STRUTIL

#include <string>
#include <vector>

namespace GRLStrUtil {
  void trim (std::string& input);
  void split (const std::string& input, std::string& first, std::string& second);
  std::vector<std::string> split(std::string input);
}


#endif


