#include "concordance.h"

using namespace std;

Concordance::Concordance(std::string filename)
{
    m_filename = filename;
    m_line = 1;
}

void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());
    while(!file.eof())
    {
        std::string word = next_word(file);
        add_word(word, m_line);
    }
}
//This function reads the entire text file and places new words into a vector. This function will also keep track of the lines that a repeated word is on. 
void Concordance::add_word(string word, int line)
{
    int find_index = -1;
    for(int i = 0; i < m_word_stats.size();++i)
    {
        if(m_word_stats[i].get_word() == word)
            {
                find_index = i;
                break;
            }
    }            
    if(find_index == -1)
    {
        Word w(word);
        w.add_line(line);
        m_word_stats.push_back(w);
    }
    else
    {
        m_word_stats[find_index].add_count(1);
        m_word_stats[find_index].add_line(line);
    }
}

//This function checks for whitespaces, new lines, and tabs.
bool Concordance::is_whitespace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t'); 
}    

//This function checks for punctuation. 
bool Concordance::is_punctuation(char c)
{
    return (c == '.' || c == ',' || c == '?' || c == '!' || c == '(' || c == ')' || c == ':' || c == ';' || c == '\"' || c == '\'');
}

//This function ignores whitespaces.
void Concordance::eat_whitespace(std::ifstream &input)
{
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            input.putback(c); // this will put the character back on the input stream 
            break; 
        }
        if (c == '\n')
            m_line++;
    }
}

//This function ignores punctuation
void Concordance::eat_punctuation(std::ifstream &input)
{
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_punctuation(c))
        {
            input.putback(c);
            break;
        }
    }
}

//This function goes to each word and makes it lowercase. 
std::string Concordance::next_word(std::ifstream &input)
{
    std::string word;
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c) && !is_punctuation(c))
        {
            word += tolower(c);
        }
        else if(is_whitespace(c))
        {
            eat_whitespace(input);
            break;
        }
        else
        {
            eat_whitespace(input);
            break;
        }
   }
   return word;
}

//This function calls m_word_stats and prints it.
void Concordance::print()
{
    for(int i = 0; i < m_word_stats.size(); ++i)
    { 
        m_word_stats[i].print();
        cout << endl;
    }
}    

