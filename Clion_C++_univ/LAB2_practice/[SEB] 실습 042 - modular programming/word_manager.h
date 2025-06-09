#ifndef WORD_MANAGER_H
#define WORD_MANAGER_H

#include <string>

void add_word(const std::string& word);
std::string normalize_word(const std::string& word);
int find_word(const std::string& word);
bool update_word(const std::string& word, size_t value);
bool delete_word(const std::string& word);
void print_words();
void reset_words();


#endif
