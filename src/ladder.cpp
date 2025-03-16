
#include <algorithm>

#include "ladder.h"



void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << " Words: " << word1 << " " << word2 << endl;
}

void str_to_lower(string & str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();
    if (abs(len1 - len2) > d) 
        return false;

    int i1 = 0, i2 = 0, num_edit = 0;
    while (i1 < len1 && i2 < len2) {
        if (str1[i1] != str2[i2]) {
            ++num_edit;

            if (num_edit > d)
                return false;

            if (len1 > len2)
                ++i1;
            else if (len2 > len1)
                ++i2;
            else {
                ++i1;
                ++i2;
            }
        } else {
            ++i1;
            ++i2;
        }

    }
    return true;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        error(begin_word, end_word, "Same word");
        return vector<string>();
    }

    if (word_list.find(end_word) == word_list.end()) {
        error(begin_word, end_word, "end word not in the dictionary");
        return vector<string>();
    }

    queue<vector<string>> ladder_queue;
    set<string> visited;
    vector<string> first_ladder = {begin_word};

    ladder_queue.push(first_ladder);
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (const string & word : word_list) {
            //if (is_adjacent(last_word, word)) cout << "adjacent " << last_word << " " << word << endl;
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                visited.insert(word);
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);

                if (word == end_word)
                    return new_ladder;
                else 
                    ladder_queue.push(new_ladder);
            }
        }
    }

    return vector<string>();

}


void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    if (!in.is_open()) {
        error(" ", file_name, "cannot open file ");
        return;
    }

    string word;
    while (in >> word) {
        str_to_lower(word);
        word_list.insert(word);
    }
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.size() == 0) {
        cout << "No word ladder found.\n";
        return;
    }
        

    for (int i = 0; i < ladder.size(); ++i) {
        cout << ladder[i] << " ";
    }
    cout << endl;
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    vector<string> ladder = generate_word_ladder("car", "cheat", word_list);
    if (ladder.size() == 0)
        cout << "No word ladder found.\n";

    print_word_ladder(ladder);
}
