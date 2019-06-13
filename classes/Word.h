#ifndef SEARCH_MACHINE_WORD_H
#define SEARCH_MACHINE_WORD_H

#include <iostream>
using namespace std;

class Word {

private:
    string text;

public:

    const string &getText() const;

    void setText(const string &text);

    void toLower();

    void replaceAccents();

    void removeNonAlfa();

    void parse(string text);

    bool operator==(const Word &rhs) const;
};


#endif //SEARCH_MACHINE_WORD_H
