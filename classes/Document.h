#ifndef SEARCH_MACHINE_DOCUMENT_H
#define SEARCH_MACHINE_DOCUMENT_H

#include <fstream>
#include <vector>
#include <map>
#include "Word.h"

class Document {

private:
    string name, path;
    vector<Word> words;
    map<string, int> wordFrquency;

    void read(string fullPath);

    void loadWordFrequency(ifstream &file);

public:

    Document(const string &name, const string &path);

    const string &getName() const;

    void setName(const string &name);

    const string &getPath() const;

    void setPath(const string &path);

    const vector<Word> &getWords() const;

    void setWords(const vector<Word> &words);

    const map<string, int> &getWordFrquency() const;

    void setWordFrquency(const map<string, int> &wordFrquency);

    bool operator==(const Document &rhs) const;
};


#endif //SEARCH_MACHINE_DOCUMENT_H
