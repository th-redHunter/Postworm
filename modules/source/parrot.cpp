#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "../../libs/logic.hpp"

int main(int argc, char* argv[])
{
 std::vector parts {get_parts(argv[1], true)};
 string_map args {get_map(parts)};

 try
 {
  std::cout << args.at("msg") << std::endl;
 }
 catch(const std::exception& e)
 {
  std::cerr << "wrong arguments" << '\n';
 }
 

 return 0;
}