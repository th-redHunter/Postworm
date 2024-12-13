#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "../../libs/logic.hpp"

int main(int argc, char* argv[])
{
  std::vector parts {get_parts(argv[1], true)};
  string_map args {get_map(parts)};

  std::string num1, num2, result;
  try
  {
   num1 = args.at("num1");
   num2 = args.at("num2");
  }
  catch(const std::exception& e)
  {
   std::cerr << "Wrong Arguments" << '\n';
  }

  result = num1 + "+" + num2;
  std::cout << result << std::endl;

  return 0;
}