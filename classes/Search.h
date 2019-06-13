#ifndef SEARCH_MACHINE_SEARCH_H
#define SEARCH_MACHINE_SEARCH_H

#include "Collection.h"

class Search {

private:
    string expression;
    vector<Word> terms;
    Collection collection;


public:
    Search(const string &expression, Collection collection);

    const string &getExpression() const;

    void setExpression(const string &expression);

    const vector<Word> &getTerms() const;

    void setTerms(const vector<Word> &terms);

    const Collection &getCollection() const;

    void setCollection(const Collection &collection);

};


#endif //SEARCH_MACHINE_SEARCH_H
