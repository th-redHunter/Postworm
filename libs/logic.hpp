#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <string>
#include <map>
#include <vector>

typedef std::map<std::string, std::string> string_map;

std::string run(
 std::string module,
 std::string path,
 string_map args
 );
std::string opt(
 std::string module,
 std::string path,
 string_map args
 );
string_map set(std::string query);

std::vector<std::string> get_parts(std::string main_line, bool schar);
string_map get_map (std::vector<std::string> parts);

#endif // LOGIC_HPP
