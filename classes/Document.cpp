#include "Document.h"


Document::Document(const string &name, const string &path = "") : name(name), path(path) {

    read(path + "/" + name);

}

const string &Document::getName() const {
    return name;
}

void Document::setName(const string &name) {
    Document::name = name;
}

const string &Document::getPath() const {
    return path;
}

void Document::setPath(const string &path) {
    Document::path = path;
}

const vector<Word> &Document::getWords() const {
    return words;
}

void Document::setWords(const vector<Word> &words) {
    Document::words = words;
}

const map<string, int> &Document::getWordFrquency() const {
    return wordFrquency;
}

void Document::setWordFrquency(const map<string, int> &wordFrquency) {
    Document::wordFrquency = wordFrquency;
}

void Document::read(string fullPath) {
    ifstream file(fullPath.c_str());

    if (file.fail())
        return;

    if(file.is_open())
        loadWordFrequency(file);

    file.close();
}

void Document::loadWordFrequency(ifstream &file) {
    string text;
    Word word;

    while (file >> text) {
        word.parse(text);
        words.emplace_back(word);

        if(wordFrquency.find(word.getText()) == wordFrquency.end()) {
            wordFrquency.insert(pair<string, int>(word.getText(), 0));
        }
        wordFrquency.find(word.getText())->second++;
    }
}

bool Document::operator==(const Document &rhs) const {
    return this->getName() == rhs.getName();
}


