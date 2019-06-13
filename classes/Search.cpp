#include <sstream>
#include <algorithm>
#include "Search.h"

Search::Search(const string &expression, Collection collection) : expression(expression), collection(collection) {
    loadTerms();
}

const string &Search::getExpression() const {
    return expression;
}

void Search::setExpression(const string &expression) {
    Search::expression = expression;
}

const vector<Word> &Search::getTerms() const {
    return terms;
}

void Search::setTerms(const vector<Word> &terms) {
    Search::terms = terms;
}

const Collection &Search::getCollection() const {
    return collection;
}

void Search::setCollection(const Collection &collection) {
    Search::collection = collection;
}

const vector<Document> &Search::getDocumentsFound() const {
    return documentsFound;
}

void Search::setDocumentsFound(const vector<Document> &documentsFound) {
    Search::documentsFound = documentsFound;
}

void Search::loadTerms() {
    string streamTerm;
    stringstream strStream(expression);
    Word word;

    while (strStream >> streamTerm) {
        word.parse(streamTerm);

        terms.emplace_back(word);

        loadDocumentsFound(word);
    }

}

void Search::loadDocumentsFound(Word word) {

    for(const auto &document : collection.getDocuments()){
        if (find(document.getWords().begin(), document.getWords().end(), word) == document.getWords().end())
            continue;

        if (find(documentsFound.begin(), documentsFound.end(), document) == documentsFound.end())
            documentsFound.emplace_back(document);
    }
}
