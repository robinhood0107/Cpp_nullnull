#ifndef WORD_MANAGER_H
#define WORD_MANAGER_H

#include <string>
#include <map>

void findWord(const std::map<std::string, size_t>& words, const std::string& word);
void updateWord(std::map<std::string, size_t>& words, const std::string& word, size_t value);
void deleteWord(std::map<std::string, size_t>& words, const std::string& word);
void printWords(const std::map<std::string, size_t>& words);

#endif
