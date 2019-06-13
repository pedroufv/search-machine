#include "Document.h"


Document::Document(const string &name, const string &path = "") : name(name), path(path) {

    loadWordFrequency(path + "/" + name);

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

void Document::loadWordFrequency(string fullPath) {
    ifstream file(fullPath);

    if (file.fail())
        return;

    string text;
    Word word;

    while (file >> text) {
        word.parse(text);

        if(wordFrquency.find(word.getText()) == wordFrquency.end()) {
            wordFrquency.insert(pair<string, int>(word.getText(), 0));
        }
        wordFrquency.find(word.getText())->second++;
    }

    file.close();
}
