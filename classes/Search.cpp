#include <sstream>
#include "Search.h"

Search::Search(const string &expression, Collection collection) : expression(expression), collection(collection) {
    string streamTerm;
    stringstream strStream(expression);
    Word word;

    while (strStream >> streamTerm) {
        word.parse(streamTerm);

        terms.emplace_back(word);
    }

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
