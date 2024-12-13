#include "libs/logic.hpp"

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

void test();

const std::string path_m {"modules/bin/"}; // path to modules
const std::string path_d {"modules/data/"}; // path to modules data
std::string c_data {"null"};
string_map args;

int main(int argc, char* argv[])
{
 std::string input;
 std::vector<std::string> inputs;
 std::string command;

 while (true)
 {
  inputs = { };
  command = "null";
  c_data = "null";
  std::cout << "(postworm)> ";
  std::getline(std::cin, input);
  inputs = get_parts(input, false);
  command = inputs.at(0);
  if (inputs.size() > 1)
   c_data = inputs.at(1);

  if (command == "run")
  {
   if (c_data != "null")
   {
    std::cout << run(c_data, path_m, args);
   }
   else
   {
    std::cout << "Where the module\n";
   }
  }
  else if (command == "opt")
  {
   std::cout << opt(c_data, path_d, args);
  }
  else if (command == "set")
  {
   try
   {
    args = set(c_data);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   
  }
  else if (command == "bad-bye")
  {
   std::cout << "fuck off\n";
   break;
  }
  else
  {
   std::cout << "options: run, opt, set, bad-bye\n";
  }
 }

 test();
 return 0;
}

void test()
{
 // code for testing
}