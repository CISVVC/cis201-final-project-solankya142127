#ifndef CONCORDANCE_H
#define CONCORDANCE_H
#include "word.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Concordance
{
public:
    Concordance(std::string filename);
    void parse();
    void add_word(string word,int line);
    std::string next_word(std::ifstream &input);
    bool is_whitespace(char c);
    bool is_punctuation(char c);
    void eat_whitespace(std::ifstream &input);
    void eat_punctuation(std::ifstream &input);
    int find_word(std::string word);
    void print();
private:
    std::vector<Word> m_word_stats;
    std::string m_filename;
    int m_line;
};

#endif
