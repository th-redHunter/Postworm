#include "logic.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

/////////
bool is_Schar(char x);
/////////

std::vector<std::string> get_parts(std::string main_line, bool schar)
{
 std::vector<std::string> parts {};

 std::string line {main_line};
 line.push_back(' ');

 int z_pnt {0};
 int e_pnt {0};
 std::string chosen {};
 bool cut_it {false};

 for (int i = 0; i < line.size(); i++)
 {
  if (line.at(i) == ' ' || line.at(i) == '\n')
  {
   e_pnt = i -1;
   cut_it = true;
  }
  
  if (is_Schar(line.at(i)) && schar)
  {
   chosen = line.substr(i, 1);
   e_pnt = i -1;
   cut_it = true;
  }
  else
  {
   chosen = "$<--->$";
  }

  if (cut_it)
  {
   parts.push_back(line.substr(z_pnt, e_pnt - z_pnt + 1));
   if (chosen != "$<--->$")
    parts.push_back(chosen);
   z_pnt = i + 1;
   cut_it = false;
  }
 }

 return parts;
}

string_map get_map (std::vector<std::string> parts)
{
 string_map final_map {};

 for (int i=0; i < parts.size(); i++)
 {
  std::string _e_, _e, e_; // element, prev-element, nxt-element
  _e_ = parts.at(i);

  if (_e_ == ":")
  {
   _e = parts.at(i - 1);
   e_ = parts.at(i + 1);

   final_map.insert((std::make_pair(_e, e_)));
  }
 }

 return final_map;
}

bool is_Schar(char x)
{
 const char chars[]{
 ';',
 ':',
 '/',
 '|',
 '_',
 // '-',
 '#',
 '(',
 ')',
 '[',
 ']',
 '$',
 '%',
 '+',
 '?'
 };

 for (int i = 0; i < sizeof(chars); i++)
 {
  if (x == chars[i])
   return true;
 }

 return false;
}