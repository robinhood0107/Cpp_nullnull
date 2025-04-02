#ifndef TOOLS_H
#define TOOLS_H

#include <string>

void std_newline(std::string& text);
std::string show_chars(const std::string& text);
std::string diff_output(const std::string& expected, const std::string& actual);

#endif // TOOLS_H