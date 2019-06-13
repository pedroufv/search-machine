#ifndef SEARCH_MACHINE_SEARCH_H
#define SEARCH_MACHINE_SEARCH_H

#include "Collection.h"

class Search {

private:
    string expression;
    vector<Word> terms;
    Collection collection;
    vector<Document> documentsFound;

    void loadTerms();
    void loadDocumentsFound(Word word);


public:
    Search(const string &expression, Collection collection);

    const string &getExpression() const;

    void setExpression(const string &expression);

    const vector<Word> &getTerms() const;

    void setTerms(const vector<Word> &terms);

    const Collection &getCollection() const;

    void setCollection(const Collection &collection);

    const vector<Document> &getDocumentsFound() const;

    void setDocumentsFound(const vector<Document> &documentsFound);

};


#endif //SEARCH_MACHINE_SEARCH_H
