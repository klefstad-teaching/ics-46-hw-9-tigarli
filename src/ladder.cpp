
#include "ladder.h"



void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << " Words: " << word1 << " " << word2 << endl;
}


bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();
    if (abs(len1 - len2) > d) 
        return false;

    int i1 = 0, i2 = 0, num_edit = 0;
    while (i1 < len1 && i2 < len2) {
        if (str1[i1] != str2[i2])
    }
}
bool is_adjacent(const string& word1, const string& word2);
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);


void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    string word;
    while (in >> word) {
        word_list.insert(word);
    }
    in.close();
}

void print_word_ladder(const vector<string>& ladder);
void verify_word_ladder();
