#include "Word.h"

const string &Word::getText() const {
    return text;
}

void Word::setText(const string &text) {
    Word::text = text;
}

void Word::toLower() {
    for (auto &letter : text) {
        letter = tolower(letter);
    }
}

void Word::removeNonAlfa() {
    for(string::iterator i = text.begin(); i != text.end(); i++)
    {
        if(!isalpha(text.at(i - text.begin())))
        {
            text.erase(i);
            i--;
        }
    }
}

void Word::parse(string text) {
    setText(text);
    toLower();
    removeNonAlfa();

}