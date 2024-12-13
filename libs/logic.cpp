#include "logic.hpp"

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>

/////////
std::string run_return(const char* script);
void show_opt(string_map args);
std::string map2raw(string_map map);
/////////

std::string run(
 std::string module,
 std::string path,
 string_map args
 )
{
 std::string script {"./"};
 script += path;
 script += module;
 script += " " + map2raw(args);
 
 return run_return(script.c_str());
}

std::string opt(
 std::string module,
 std::string path,
 string_map args
 )
{
 if (module == "null")
 {
  show_opt(args);
  return "\n[+] Pick up your F data\n";
 }

 std::string script {"cat "};
 script += path;
 script += module;
 script += ".ayd";
 return run_return(script.c_str());
}

string_map set(std::string query)
{
 if (query == "null")
 {
  throw "[-] where the TFDYWTS aka (the fucking data you want to set)\n";
 }

 printf("[+] your query %s\n", query.c_str());
 std::vector parts {get_parts(query.c_str(), true)};
 string_map map {get_map(parts)};
 show_opt(map);
 std::cout << "[+] the data updated successfully\n";
 return map;
}

//////////////////////////////////
//////////////////////////////////

void show_opt(string_map args)
{
 std::string result;

 std::cout << "|key|\t|value|\n";
 std::cout << "------------------\n";
 for (const auto& element : args)
 {
  const char* key = element.first.c_str();
  const char* value = element.second.c_str();
  printf("%s\t%s\n", key, value);
  std::cout << "------------------" << std::endl;
 }
}

std::string run_return(const char* script)
{
 printf("\n[+] Run the script: %s.\n", script);

 FILE* pipe = popen(script, "r");
 if (!pipe)
 {
  throw "Failed to run the module.\n";
 }

 char buffer[128];
 std::string result;
 while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
 {
  result += buffer;
 }
 pclose(pipe);

 return result;
}

std::string map2raw(string_map map)
{
 std::string result;

 for (const auto& element : map)
 {
  const char* key = element.first.c_str();
  const char* value = element.second.c_str();
  result += key;
  result += ":";
  result += value;
  result += "+";
 }
 return result;
}
